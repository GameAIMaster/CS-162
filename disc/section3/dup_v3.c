#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	// Place an all done to terminal when ls finishes
	// Hint: You need fork and wait
	int pid, status;
	int newfd;
	char *cmd[] = { "/bin/ls", "-al", "/", 0 };
	if (argc != 2) 
	{
		fprintf(stderr, "usage: %s output_file\n", argv[0]);
		exit(1);
	}
	if ((newfd = open(argv[1], O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0) 
	{
		perror(argv[1]);    
		/* open failed */
		exit(1);
	}
	printf("writing output of the command %s to \"%s\"\n", cmd[0], argv[1]);
	dup2(newfd, 1);
	execvp(cmd[0], cmd);
	perror(cmd[0]);     
	/* execvp failed */
	exit(1);
}

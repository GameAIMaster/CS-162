#include <stdio.h>
#include "advanced1-sol.h"
#include "advanced2.h"

int global = 2;

int main () {
    global++;
    change_global ();
    printf ("%d\n", global);
}

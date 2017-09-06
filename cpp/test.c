/*main.c*/
/*-------------------------*/
/* global variable */
#include <unistd.h>
#include <stdio.h>
char *glo_ppa[4];
int main() {
    /* global variable */
    char *loc_ppa[4];
    printf("%d\n", glo_ppa[4]);
    printf("%d\n", loc_ppa[4]);
    exit(0);
}


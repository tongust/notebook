#include <stdio.h>
#include <stdlib.h>     /* getenv */


extern char **environ;

char *p0;
int main() {
    char ** p = environ;
    for (; *p != NULL; p++) {
        printf("%s\n", *p);
    }
    p0 = getenv("PATH");
    printf("%s\n", p0);
    return 0;
}

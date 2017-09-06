#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "tlpi_hdr.h"


int main (int argc, char **argv ) {
    if (argc < 2)
    {
        usageErr("%s file", argv[0]);
    }
    int fd = open(argv[1], O_WRONLY);
    if (fd != -1) {
        printf("[pid %ld] %s allready exists\n", (long) getpid(), argv[1]);
        close(fd);
    } else {
        if (errno != ENOENT) {
            errExit("Open"); // failed for unexpected reason.
        } else {
            printf("[pid %ld] %s doesn't  exist yet \n", (long) getpid(), argv[1]);
            if (argc > 2) {
                sleep(5);
                printf("[pid %ld] %s sleeping done \n", (long) getpid(), argv[1]);

            }
            fd = open(argv[1], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IROTH);
            printf("[pid %ld] %s Create file \n", (long) getpid(), argv[1]);
            
        }
    }

    exit(EXIT_SUCCESS);
}

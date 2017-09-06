#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "tlpi_hdr.h"
#define BUFFER_SIZE_ 128
char mbuf[BUFFER_SIZE_+1];


int main()  {
    int fd = open("tfile", O_RDWR);
    if(fd == -1) {
        errExit("open");
    }
    ssize_t numRead;
    ssize_t ot = lseek(fd, 0, SEEK_DATA);// Need D_GNU_SOURCE
    printf("%ld", ot);
    while ((numRead = read(fd, mbuf, BUFFER_SIZE_)) > 0) {
        mbuf[numRead] = '\0';
        printf("%s,%ld\n", mbuf, numRead);
        break;
    }
    ot = lseek(fd, ot, SEEK_HOLE);
    printf("%ld", ot);
    if (numRead == -1) {
        errExit("Read");
    }
    close(fd);
    return 0;
}


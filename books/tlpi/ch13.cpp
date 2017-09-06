#include <iostream>
#include <string>
#include <stdio.h>
#include <initializer_list>
#include <stdlib.h>     /* getenv */
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "tlpi_hdr.h"

/*implement of tail -n*/

#define M_BUF_SIZE 1024

using namespace std;

int main(int argc, char **argv) {
    if (argc < 3 || strcmp(argv[1],"--help") == 0) {
        errExit("input n file");
    }
    int fd = open(argv[2], O_RDONLY);
    if (fd == -1) 
        errExit("Open");
    char *buf = (char *)malloc(M_BUF_SIZE+1);
    if (!buf)
        errExit("malloc");
    int numRead = 0;
    int nline = std::stoi(string(argv[1]));
    stoi(string("1"));
    if (nline <= 0) return 0;
    size_t mc = 0, mc1 = 0;
    while ( (numRead = read(fd, buf, M_BUF_SIZE)) > 0) {
        for (int i = 0; i < numRead; ++i) {
            if (buf[i] == '\n')
                mc++;
        }
    }
    if (mc == 0)return 0;
    if (nline > mc)
        mc1 = mc;
    else 
        mc1 = mc -  nline;
    if (lseek(fd, 0, SEEK_SET) == -1) {
        errExit("lseek");
    }
    mc = 0;
    while ( (numRead = read(fd, buf, M_BUF_SIZE)) > 0) {
        for (int i = 0; i < numRead; ++i) {
            if (buf[i] == '\n')
                mc++;
            if (mc == mc1) {
                mc1 = numRead - i - 1;
                break;
            }
        }
    }
    off_t o1 = -mc1;
    if (lseek(fd,o1, SEEK_CUR) == -1) {
        errExit("lseek");
    }

    while ( (numRead = read(fd, buf, M_BUF_SIZE)) > 0) {
        if (write(1, buf, numRead) != numRead) {
            fatal("couldn't output");
        }
    }
    if (numRead == -1)
        errExit("read");

    if (close(fd) == -1)
        errExit("close input");
    if (close(1) == -1)
        errExit("close output");
    free(buf);
    return 0;
}

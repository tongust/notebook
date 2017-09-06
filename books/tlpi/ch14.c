#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

char buf[500010];

int 
main() {
    int nto, nw;
    char *ptr;


    /* function  */
    auto set_fl = [](int fd, int flgs)->void {
        int val;
        val = fcntl(fd, F_GETFL, 0);
        val |= flgs;
        fcntl(fd, F_SETFL, val);
        return;
    };
    auto clr_fl = [](int fd, int flgs)->void {
        int val;
        val = fcntl(fd, F_GETFL, 0);
        val &= ~flgs;
        fcntl(fd, F_SETFL, val);
        return;
    };
    nto = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %d bytes\n", nto);
    set_fl(STDIN_FILENO, O_NONBLOCK); /* IO nonblocking */
    ptr = buf;
    while (nto > 0) {
        errno = 0;
        nw = write(STDOUT_FILENO, ptr, nto);
        fprintf(stderr, "nw = %d, errno = %d\n", nw, errno);

        if (nw > 0) {
            ptr += nw;
            nto -= nw;
        }
    }

    clr_fl(STDOUT_FILENO, O_NONBLOCK);

    return 0;

}

/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2016.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 24-2 */

/* fork_file_sharing.c

   Show that the file descriptors of a forked child refer to the
   same open file objects as the parent.
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "tlpi_hdr.h"
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int fd, flags;
    char template[] = "/tmp/testXXXXXX";

    setbuf(stdout, NULL);                   /* Disable buffering of stdout */

    /* Open a temporary file, set its file offset to some arbitrary value,
       and change the setting of one of the open file status flags. */

    fd = mkstemp(template);
    if (fd == -1)
        errExit("mkstemp");
    switch (fork()) {
    case -1:
        errExit("fork");

    case 0:     /* Child: change file offset and status flags */
        flags = fcntl(fd, F_GETFL);         /* Fetch current flags */
        if (flags == -1)
            errExit("fcntl - F_GETFL");
        flags |= O_RDWR;

        char mf[] = "From child\n";
        size_t a = 11;
        lseek(fd, 0, SEEK_SET);
        fcntl(fd, F_SETFL, flags);
        a = write(fd, mf, a);
        printf("has writen %ld\n", a);
        _exit(EXIT_SUCCESS);

    default:    /* Parent: can see file changes made by child */
        if (wait(NULL) == -1)
            errExit("wait");                /* Wait for child exit */
        printf("Child has exited\n");
        flags |= O_RDWR;
        if (fcntl(fd, F_SETFL, flags) == -1)
            errExit("fcntl - F_SETFL");
        lseek(fd, 0, SEEK_SET);
        char mr[200];
        size_t mc = 11;
        size_t aa = read(fd, mr, mc);
        mr[mc] = '\0';
        printf("hello %s\n, %lld\n", mr, aa);
        exit(EXIT_SUCCESS);
    }
}

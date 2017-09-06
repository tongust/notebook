/*
 * exercisre 9-3
 */

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/fsuid.h>
#include <limits.h>
#include "ugid_functions.h" /* groupIdFromName  */
#include "tlpi_hdr.h"
#include <grp.h>
#include <sys/types.h>


char *p5[3];
char **p4= p5;
int main(int argc, char **argv) {
    uid_t ruid, euid, suid, fsuid;
    gid_t rgid, egid, sgid, fsgid;

    char *p = NULL;
    if (getresuid(&ruid, &euid, &suid) == -1)
        errExit("getresuid");
    if (getresgid(&rgid, &egid, &sgid) == -1)
        errExit("getresgid");
    struct group * mgetg;
    int mc = 0;
    printf("%d", sizeof(p5));
    
    if (p5[3] == NULL)printf("wrong\n");
    while (mgetg = getgrent()) {
        char **pptr = mgetg->gr_mem;
        mc++;
        if (mc ==5) {
            printf("****%d\n", mgetg->gr_mem[1]);
            char **p4 = pptr;
            int icc = 0;
            while (pptr[icc] != NULL) {
                printf(">>>>>>>>>>%d\n", icc);
                icc++;
            }
        }
        //char a[] = "hello";
        printf("%d\n", sizeof(pptr));
    }

    return 0;
}

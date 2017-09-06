#include <unistd.h>
#include <sys/wait.h>
#include <iostream>


using namespace std;
int main() {
    cout << getpid() << endl;
    cout << "init process\n";
    pid_t childPid;
    int childStatus;
    switch(childPid = fork()) {
        case -1:
            cerr << "wrong\n";
            exit(1);
            break;
        case 0: // child preocess, fork() called by child return 0, while it called by parent returns process ID of children.
            cout << "From child, getpid\t" << getpid() << endl;
            cout << "From child, childPid\t" << childPid << endl;
            cout << "Child Parent\t" << getppid() << endl;
            //sleep(1); // 10s 
            break;
        default: // parent process
            cout << "From parent, getpid\t" << getpid() << endl;
            cout << "From parent, childPid\t" << childPid << endl;
            cout << "Parent Parent\t " << getppid() << endl;
            // wait
            cout << "wait...\n";
            pid_t tmpid = wait(&childStatus);
            while (tmpid != childPid) {
                tmpid = wait(&childStatus);
                sleep(1);
            }
            break;
    }
    return 0;
}

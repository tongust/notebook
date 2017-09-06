#include <time.h>
#include <unistd.h>
#include <sys/times.h>
#include <iostream>

using namespace std;


int main() {
    clock_t tic = clock();
    long clockTicks = CLOCKS_PER_SEC;
    sleep(1);
    cout << clockTicks << endl;
    cout << (1.0/clockTicks)*(clock()-tic) << endl;
    return 0;
}

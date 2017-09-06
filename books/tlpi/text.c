#include <stdlib.h>

int varGuninit; // Global 0-initialized var
int varGinit = 12; // Global user-initialized var
static int varStatVar = 12; // Global static initialized var
int main() {
    /*local variable*/
    int a;
    int b = 10;
    /* local static var */
    static int statUninit; // 0-initialized
    static int statInit = 0; // User-initialized
    char *p =  (char*)malloc(b);
    free(p);
    return 0;
}

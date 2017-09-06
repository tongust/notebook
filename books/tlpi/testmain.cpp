#include <iostream>

extern "C" {
    int foo();
}
int main() {
    foo();
    return 0;
}

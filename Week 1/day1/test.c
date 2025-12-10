#include <stdio.h>

int main() {
    int x;
    printf("%d\n", x); // using uninitialized variable
    int unused = 10;   // unused variable
    return 0;
}

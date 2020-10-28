#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = NULL;
    puts("before invaild access");
    *p = 0;
    puts("after invaild access");
    exit(EXIT_SUCCESS) 
}

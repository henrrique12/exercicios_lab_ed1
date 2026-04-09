#include <stdio.h>

int main(){
    int n = 5;
    int *p = &n;

    *p = 20;

    printf("Novo valor de n: %d", n);

    return 0;
}
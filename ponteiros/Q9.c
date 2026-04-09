#include <stdio.h>

int main() {
    int x = 10;     
    int *p = &x;     
    int **pp = &p;   

    printf("Valor de x: %d\n", x);      
    printf("Valor de *p: %d\n", *p);   
    printf("Valor de **pp: %d\n", **pp); 

    return 0;
}

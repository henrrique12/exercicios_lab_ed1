#include <stdio.h>

void inverter(int *v, int n) {
    for (int i = 0; i < n/2; i++) {
        int temp = *(v+i);                  
        *(v+i) = *(v+(n-1-i));              
        *(v+(n-1-i)) = temp;               
    }
}

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Vetor original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    inverter(v, n); 

    printf("\nVetor invertido: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}

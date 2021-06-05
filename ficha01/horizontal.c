#include<stdio.h>

void triangulo(int x) {
    int contador = 0;
    for(int i = 1; i <= x; i++) {
        int espacos = x - i;
        while(espacos) {
            printf(" ");
            espacos--;
        }
        for(int j = 1; j <= (1 + 2*contador); j++) {
            printf("#");
        }
        printf("\n");
        contador++;
    }
}

/*
int main() {
    int x = 5;
    horizontal(5);
    return 0;
}
*/
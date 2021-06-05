#include<stdio.h>

void triangulo(int x) {
    int contador = 1;
    
        for(int j = 1; j <= x; j++) {
           for(int i = 0; i < contador; i++) {
               printf("#");
           }
           printf("\n");
           contador++;
        } 
        contador--;
        for(int j = x; j < (2 * x - 1); j++) {
            for(int i = 1; i <= contador - 1; i++) {
                printf("#");
            }
            printf("\n");
            contador--;
        }

}

/*
int main() {
    int x = 5;
    vertical(5);
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quadrado(int x) {

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < x; j++) {
            if(j == x - 1) printf("#\n");
            else printf("#");
        }
    }
}

void xadrez(int x) {
    for(int i = 0; i < x; i++) {
        if((i % 2 == 0)) {
          for(int j = 0; j < x; j++) {
            if((j % 2 == 0)) printf("#");
            else printf("_");
            if(j == x - 1) printf("\n");
        }
        } else {
            for(int j = 0; j < x; j++) {
            if((j % 2 == 0)) printf("_");
            else printf("#");
            if(j == x - 1) printf("\n");
        }
        }
    }
}

int circulo() {
    int raio, a, count = 0;
    printf("Insira o raio desejado: ");
     scanf("%d", &raio);
    for(int i=-raio;i<raio;i++) {
        for(int j=-raio;j<raio;j++) {
            if(i*i+j*j<raio*raio) {
                printf("#");
                count++;
            }
            else
                printf(" ");
                
        }
        printf("\n");
    }
    printf("\n");
    return count;
}

int main() {
    int x = 5;
    //quadrado(x);
    //xadrez(x);
    circulo();
    return 0;
}
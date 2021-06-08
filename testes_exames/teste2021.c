#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

typedef struct nodo {
	int valor;
	struct nodo *pai, *esq, *dir;
} *ABin;

//Exercicio 1, 100ª menor parcela do somatorio ou -1 caso gaja menos do q 100
int sumhtpo(int n) {
    int r = 0, i = 0, j, aux = 0, temp;
    
    int* arr;
    arr = (int*)malloc(sizeof(int)*aux);

    while(n != 1) {
        arr[aux] = n;
        aux++;
        r += n;
        if(n % 2 == 0) n = n / 2; else n = 1+(3*n);
    }
    
    if(aux >= 99) {
    for(i = 0; i < aux; i++) {
        for(j = i + 1; j < aux; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
        return arr[99];
    }
    
   return -1;
   
}

//Exercicio 2

int moda(int v[], int N, int *m) {
    if(N == 0) return 0;
    int maxValue = 0,maxCount = 0, i, j, flag = 1;
    
    for(i = 0; i < N; i++) {
        int count = 0;

        for(j = 0; j < N; j++) {
            if(v[j] == v[i]) count++;
        }
        if(count == maxCount && v[i] != maxValue) {
            flag = 1;
        } else if(count > maxCount) {
            maxCount = count;
            maxValue = v[i];
            flag = 0;
        }
    }
    if(flag == 1) return 0;
    else {
        m = &maxValue;
        printf("A moda é: %d\n", *m);
        return maxCount;
    }
}


//Exercicio 3, agora percebi 
int procura(LInt *l, int x) {
    int count = 0;
    LInt aux = *l;
    while(aux != NULL) {
        if(aux->valor == x) {
            LInt temp = *l;
            *l = malloc(sizeof(struct lligada));
            (*l)->valor = x;
            (*l)->prox = temp;
            l = &(*l)->prox;
            for(;(*l); l=&(*l)->prox) {
                if((*l)->valor == x) {
                    LInt temp = *l;
                    *l = (*l)->prox;
                    free(temp);
                }
            }
    return 1;    
        }
        aux = aux->prox;
    }
    return 0;
}

//Exercicio 4, acho que percebi, testei no codeboard das 100questoes
int freeAB(ABin a) {
    int r = 0;
    if(a) {
        r += 1 + freeAB(a->esq) + freeAB(a->dir);
        free(a);
    }
    return r;
}

LInt getLInt(int len) {
    if(len == 0) return NULL;
    LInt new = malloc(sizeof(struct lligada));
    printf("Insere um valor: ");
    int num;
    scanf("%d",&num);
    new->valor = num;
    new->prox = getLInt(len - 1);
    return new;
}

void printLInt(LInt l) {
    if(l == NULL) putchar('\n');
    else {
        printf("%d ",l->valor);
        printLInt(l->prox);
    }
}

int main() {
    /* 
    LInt list1;
    list1 = getLInt(10);
    printLInt(list1);
    int res = procura(&list1, 99);
    printLInt(list1);
    printf("Deu return: %d\n", res);
    */
    /* 
    //EX1
    int r1 = sumhtpo(1000);
    printf("%d\n", r1);
    */
   /*
    //2
    int v[21] = {1,1,1,1,1,5,5,5,5,5,2,8,86,6,4,6,6,6,6,6,6};
    int *m;
    int r2 = moda(v, 21, m);
    printf("%d é a freq\n", r2);
    */
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//Parte A - COMEÇA AQUI
//Ex1
char *mystrstr (char s1[], char s2[]) {
    char *ret = NULL;
    int i, j, l;
    
    if (!(*s2))
        ret = s1;

    for (i = 0; s1[i] && !ret; i++) {
        for (j = 0, l = i; s1[l] == s2[j] && s2[j]; l++, j++);
        if (!s2[j])
            ret = s1 + i;
    }
  
    return ret;
}
//Ex2
void truncW (char t[], int n) {
    int i, j, count = 0;

    for(i = 0; t[i]; i++) {
        if(t[i] != ' ') count++;
        else count = 0;

        if(count > n) {
            for(j = i; t[j]; j++) {
                t[j] = t[j+1];
            }
            i--;
        }
    }
}

//Ex3
typedef struct posicao {
    int x, y;
} Posicao;

int maiscentral (Posicao pos[], int N) {
    int i, closest = 0, dist, temp;
    for(i = 0; i < N; i++) {
        temp = pow(pos[i].x, 2) + pow(pos[i].y, 2);
        if(temp < dist || i == 0) {
            dist = temp;
            closest = i;
        }
    }
    return closest;
}

//Ex4
typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

LInt somasAcL (LInt l) {
    int soma = 0;
    LInt ret = NULL, temp = NULL;
    for(; l; l = l->prox ) {
        soma += l->valor;
        LInt aux = malloc(sizeof(LInt));
        aux->valor = soma;
        aux->prox = NULL;
        if(ret == NULL) ret = temp = aux;
        else temp = temp->prox = aux; 
    }

    return ret;
}

//Ex5 
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int addOrd (ABin *a, int x) {
    while(*a) {
        if((*a)->valor == x) return 1;
        if((*a)->valor > x) a = &((*a)->esq);
        else a = &((*a)->dir);
    }
    ABin new = malloc(sizeof(struct nodo));
    new->valor = x;
    new->esq = new->dir = NULL;
    (*a) = new;
    return 0;
}
//PARTE B - COMEÇA AQUI

typedef struct celula {
    char *palavra;
    int comp;
struct celula *prox;
} *Palavras;

int daPalavra (char *s, int *e) {
    for((*e) = 0; isspace(s[(*e)]);(*e)++);
    int len;
    for(len = 0; !isspace(s[len + (*e)]) && s[len + (*e)] != '\0';len++);
    return len;
}

Palavras words (char *texto) {
    if(!words) return NULL;
    int e, n;
    n = daPalavra(texto, &e);
    if(!n) return NULL;
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = texto + e;
    new->comp = n;
    new->prox = words(texto + e + n);
    return new;
}

//Ex3
Palavras daLinha (Palavras t, int n) {
    int len = 0;
    Palavras prev;
    for(;len < n && t; t = t->prox) {
        len += t->comp + 1;
        if(len > n) break;
        prev = t;
    }
    t = prev->prox;
    prev->prox = NULL;
    return t;
}
//Ex4
void tamanhoLinha (Palavras p, int* numP) {
    int len = 0;
    (*numP) = 0;
    while(p) {
        len += p->comp;
        if(p->prox) len++;
        (*numP)++;
        p = p->prox;
    }
}

void escreveLinha (Palavras p, int n) {
    int numP;
    int len = tamanhoLinha(p, &numP);
    if(numP == 1) printf("%s\n", p->palavra);
    else {
        int espacos = n - len;
        while(p) {
            for(int i = 0; i < p->comp; i++) putchar(p->palavra[i]);
            numP--;
            if(p->prox) {
                putchar(' ');
                for(;(espacos/numP) > 0; espacos--) putchar(' ');
            }
            p = p->prox;
        }
    }
    printf("\n");
}

//5

void formata (char texto[], int largura) {
    Palavras pals = words(texto);
    Palavras resto;
    while(resto = daLinha(pals, largura)) {
        escreveLinha(pals, largura);
        pals = resto;
    }
    escreveLinha(pals, largura);
}
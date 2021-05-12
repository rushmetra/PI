#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} Celula, * Palavras;

// Exercicio 1
void libertaLista (Palavras l) {
    Palavras tmp;
    while(l != NULL) {
        tmp = l;
        l = l->prox;
        free(tmp);
    }
}

void libertaLista2 (Palavras l) {
    if (l) {
        libertaLista2(l->prox);
        free(l);
    }
}

// Exercicio 2
int quantasP (Palavras l) {
    int count = 0;
    while(l != NULL) {
        count++; 
        l = l->prox;
    }
    return count;
}

// Exercicio 3
void listaPal (Palavras l) {
    while(l){
        printf("%s :: %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

// Exercicio 4
char* ultima (Palavras l) {
    while(l && l->prox) l = l->prox;

    if(l) return l->palavra;
    else return NULL;

}

// Exercicio 5
Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras aux = malloc(sizeof(Celula));
    aux->palavra = strdup(p);
    aux->ocorr = 1;
    aux->prox = l;
    return aux;
}

// Exercicio 6
Palavras acrescentaFim (Palavras l, char *p) {
    Palavras aux  = malloc(sizeof(Celula));
    Palavras aux2 = l;
    aux->palavra = strdup(p);
    aux->ocorr = 1;
    aux->prox = NULL;
    while(l && l->prox) l = l->prox;
    if(l){
        l->prox = aux;
        return aux2;
    }
    else return aux; //se a lista fosse vazia, eu retorno uma lista com apenas a minha palavra inserida
}

// Exercicio 7

Palavras acrescenta (Palavras l, char *p) {
    if(!l || (strcmp(p,l->palavra) < 0))
        return acrescentaInicio(l,p);
    else if (strcmp(p,l->palavra) == 0) {
        l->ocorr++;
        return l;
    }
    else {
        l->prox = acrescenta(l->prox,p);
        return l;
    }
}

Palavras maisFreq (Palavras l) {
    Palavras res = NULL;
    int max = 0;
    while(l) {
        if(l->ocorr > max) {
            res = l;
            max = l->ocorr;
        }
        l = l->prox;
    }
    return res;
}

int main () {
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    libertaLista2 (dic);

    
    dic = NULL;

    srand(42);
    
    for (i=0; i<1000; i++)
        dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));
    
    p = maisFreq (dic);
    //printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);
    

   
    printf ("\n_________ Fim dos testes _________\n\n");

    return 0;
}
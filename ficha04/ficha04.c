#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int contaVogais (char *s){
    int count = 0;
    while(*s) {
        if(*s == 'A' || *s == 'a' || *s == 'E' || *s == 'e' || *s == 'I' ||
        *s == 'i' || *s == 'O' || *s == 'o' || *s == 'U' || *s  == 'u') count++;
        *s++;
    }
    return count;
}

int pertence(char letras[], char c) {
    int i = 0;
    while(letras[i] != c && letras[i] != '\0') {
        i++;
    }
    return (letras[i] == c)? 1 : 0;
}

int contaLetras(char *s, char *letras) {
    int sum = 0;
    while(*s) {
        if(pertence(letras, *s)) {
            sum++;
        }
        s++;
    }
    return sum;
}
/*
int retiraVogaisRep (char *s){
    char *aux;
    int count = 0;
    while(*s) {
        if(*s == *s+1) {
            *s++;
            count++;
        }
        else {
            *aux = *s;
            *aux++;
            *s++;
        }
    }
    *s = *aux; 
    return count;
}
*/

int eVogal(char s) {
    if(s == 'A' || s == 'a' || s == 'E' || s == 'e' || s == 'I' ||
    s == 'i' || s == 'O' || s == 'o' || s == 'U' || s  == 'u') return 1;
    else return 0;
}
int retiraVogaisRep (char *s){
    int contador = 0;
    int i = 0, j;
    while (s[i]!='\0') 
        if(eVogal(s[i]) && s[i+1]==s[i]) {
            contador++;
            for(j=i+1;s[j]!='\0';j++)
            s[j]=s[j+1];
        }
        else i++;
    return contador;
}

int duplicaVogais (char *s) {
    char o[strlen(s)+contaVogais(s)+1];
    int i=0,j=0,cont = 0;
    while (s[i] != '\0'){
        if (eVogal (s[i])){
            o[j] = o[j+1] = s[i];
            i++;
            j+=2;
            cont++;
        }
        else{
            o[j] = s[i];
            i++;
            j++;
        }
    }
    o[j] = '\0';
    strcpy(s,o);
    
    return cont;
}

int ordenado (int v[], int N) {
    int r = 0;
    int i;
    for(i = 0; i < N; i++) {
        if(v[i] > v[i+1]) return 0;
        else r = 1;
    }

    return r;
}

void merge (int a[], int na, int b[], int nb, int r[]) {
    int i = 0, j = 0, h = 0;
    while(i < na && j < nb) {
        if(a[i] < b[j]) {
            r[h] = a[i];
            h++;
            i++;
        } else {
            r[h] = b[j];
            h++;
            j++;
        }
    }
    while(i < na) {
        r[h] = a[i];
        i++;
        h++; 
    }
    while(j < nb) {
        r[h] = b[j];
        j++;
        h++;
    }
}

int partition(int v[], int N, int x) {
    int j = 0, i;
    int aux[N];
    for(i = 0; i < N; i++) {
        if(v[i] <= x) {
            aux[j] = v[i];
            j++;
        }
    }
    int contador = j;

    for(i = 0; i < N && j < N; i++) {
        if(v[i] > x) {
            aux[j] = v[i];
            j++;
        }
    }
    
    for(i = 0; i < N; i++) {
        v[i] = aux[i];
    }
    return contador;
}
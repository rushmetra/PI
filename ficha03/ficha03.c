#include <stdio.h>

void swapM (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap (int v[], int i, int j) {
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int soma (int v[], int N) {
    int i, r = 0;
    for(i = 0; i < N; i++) {
        r += v[i];
    }
    return r;
}

void inverteArray (int v[], int N) {
    int i;
    for(i = 0; i < N; i++) {
        swap(v, i - 1, N);
        N--;
    }
}

void inverteArrayM (int v[], int N) {
    int i;
    for(i = 0; i < N; i++) {
        swapM(&v[i - 1], &v[N]);
        N--;
    }
}

int maximum (int v[], int N, int *m) {
    if(N == 0) return 1;
    int i;
    *m = v[0];
    for(i = 1; i < N; i++) {
        if(v[i] > *m) *m = v[i];
    }
    return 0;
}

void quadrados (int q[], int N) {
    int i;
    for(i = 0; i < N; i++) {
        q[i] = (i+1)*(i+1);
    }
}

void pascal (int v[], int N) { // está a dar mal idk why
    if(N == 1) v[0] = 1;
    else {
        int i;
        int linhaanterior[N - 1];
        pascal(linhaanterior, N - 1);
        v[0] = 1;
        v[N-1] = 1;
        for(i = 1; i < N - 1; i++) {
            v[i] = linhaanterior[i - 1] + linhaanterior[i];
        }
    }
}

int main() {
    int x = 3, y = 5;
    swapM(&x, &y);
    printf("%d %d\n", x, y);
    return 0;
}
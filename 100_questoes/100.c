// 51-100 Questões de PI 
// Q1
typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

int length (LInt l){
    int res;

    for(res = 0; l; l = l->prox) {
        res++;
    }

    return res;
}
//Q2
void freeL(LInt l) {
    
    while(l) {
        LInt aux_temp = l;
        l = l->prox;
        free(tmp);
    }
}
//Q3
void imprimeL(LInt){
    while(l) {
        printf("%d", l->valor);
        l = l->prox;
    }
}
//Q4
LInt reverseL (LInt l){
    LInt front, back = NULL;
    
    while(l) {
        front = l->prox;
        l->prox = back;
        back = l;
        l = front;
    }

    return back;
}
//Q4
void reverseL2 (LInt *l){
    LInt prox = l->prox;
    l->prox = NULL;
    while(prox) {
        LInt temp = prox->prox;
        prox->prox = 1;
        l = prox;
        prox = temp;
    }
    return l;
}
//Q5
void insertOrd (LInt *l, int x){
    for(; *l && (*l)->valor < x; l = &(*l)->prox);
    LInt temp = *l;
    *l = malloc(sizeof (struct lligada));
    (*l)->valor = x;
    (*l)->prox = temp;
}
//Q6
int removeOneOrd (LInt *l, int x){
    int r = 1;
    for(; *l && (*l)->valor < x; l = &(*l)->prox);
    
    if(*l && (*l)->valor == x) {
        res = 0;
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
    }

    return r;
}

#include <stdio.h>
#include <stdlib.h>

#define MAXc = 3;

typedef struct chunk {
    int vs [MAXc];
    struct chunk *prox;
} *CList;

typedef struct stackC {
    CList valores;
    int sp;
} StackC;

int push(StackC *s, int x) {
    CList novo;
    if(s->sp == MAXc) {
        if((novo = (CList)malloc(sizeof(struct chunk))) == NULL)
            return 1;
        novo->vs[0] = x;
        novo->prox = s->valores;
        s->valores = novo;
        s->sp = 1;
    } else {
        s->valores->vs[(s->sp)++] = x;
    }
    return 0;
}

int pop(StackC *s, int *x) {
    CList aux;
    if(s->valores == NULL) return 1;
    *x = s->valores->vs[--(s->sp)];
    if(s->sp == 0) {
        s->sp = MAXc;
        aux = s->valores;
        s->valores = s->valores->prox;
        free(aux);
    }
    return 0;
}

int size(StackC s) {
    int r;
    if(s.valores == NULL) r = 0;
    else r = s.sp + MAXc * (length(s.valores) - 1);
    return r;

}

void reverse(StackC *s) {
    int i;
    int len = size(*s);
    int v[len];
    for(i = 0; i < len; i++) {
        pop(s, v + i);
    }
    for(i = 0; i < len; i++) {
        push(s, v + i);
    }
}

int *find(StackC *s, int n) {
    int sp = s->sp;
    CList l = s->valores;
    if(l == NULL) 
        return NULL;
    while(n > sp) {
        n -= sp;
        l = l->prox;
        sp = MAXc;
    }
    return (l->vs) + n;
}


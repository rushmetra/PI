// 51-100 Questões de PI 
// Q1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        free(aux_temp);
    }
}
//Q3
void imprimeL(LInt l){
    while(l) {
        printf("%d\n", l->valor);
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
//Q4 ver melhor
void reverseL2 (LInt *l){
    LInt prox = (*l)->prox;
    (*l)->prox = NULL;
    while(prox) {
        LInt temp = prox->prox;
        prox->prox = 1;
        l = prox;
        prox = temp;
    }
    return l;
}
//Q5 ver melhor
void insertOrd (LInt *l, int x){
    for(; *l && (*l)->valor < x; l = &(*l)->prox);
    LInt temp = *l;
    *l = malloc(sizeof (struct lligada));
    (*l)->valor = x;
    (*l)->prox = temp;
}
//Q6 ver melhor
int removeOneOrd (LInt *l, int x){
    int r = 1;
    for(; *l && (*l)->valor < x; l = &(*l)->prox);
    
    if(*l && (*l)->valor == x) {
        r = 0;
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
    }

    return r;
}
//Q7
void merge (LInt *r, LInt l1, LInt l2){
   if(!l1 && !l2) return;
   if(l2 == NULL || l1 != NULL && l1->valor < l2->valor) {
       (*r) = l1;
       merge(&((*r)->prox), l1->prox, l2);
   } else {
       (*r) = l2;
       merge(&((*r)->prox), l1, l2->prox);
   }
}
void mergeL (LInt *r, LInt l1, LInt l2){
    for (; l1 || l2; r = &(*r)->prox) {
        if ((l1 && l2 && l1->valor < l2->valor) || !(l2)) {
            *r = l1;
            l1 = l1->prox;
        }
        else {
            *r = l2;
            l2 = l2->prox;
        }
    }
    *r = NULL;
}
//Q8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){

    for(; l; l = l->prox) {
        if(l->valor < x) {
            *mx = l;
            mx = &(*mx)->prox;
        } else {
        *Mx = l;
        Mx = &(*Mx)->prox;
        }
    }
    *mx = *Mx = NULL;
}
//Q9
LInt parteAmeio (LInt *l){
    int i, count;
    LInt y = (*l), prev = NULL;
    for(i = 0; *l; l = &(*l)->prox) count++; 
    if((count/2) == 0) return NULL;
    for(i = 0; i < (count/2); i++) {
        prev = (*l);
        (*l) = (*l)->prox;
    }
    prev->prox = NULL;
    return y;
}
//Q10 consegui
int removeAll (LInt *l, int x){
    int count = 0;
    while(*l) {
        if((*l)->valor == x) {
            (*l) = (*l)->prox;
            count++;
        } else {
            l = &(*l)->prox;
        }
    }

    return count;
}
//Q11
int removeDups (LInt *l){
    int count = 0;
    for(; *l; l = &(*l)->prox) {
        LInt* ocorre = &(*l)->prox;
        while(*ocorre) {
            if((*ocorre)->valor == (*l)->valor) {
                LInt temp = *ocorre;
                *ocorre = (*ocorre)->prox;
                free(temp);
                count++;
            } else {
                ocorre = &(*ocorre)->prox;
            }
        }
    }
    return count;
}
//Q12
int maximo (LInt l); //pergunta 18
int removeMaiorL (LInt *l){
    int maior = maximo(*l);     
    
    for (; (*l)->valor != maior; l = &(*l)->prox);
    
    LInt temp = *l;
    *l = (*l)->prox;
    free(temp);
    
    return maior;
}
//Q13 yauuu
void init (LInt *l){
    for(; *l && (*l)->prox; l = &(*l)->prox);
        free(*l);
        *l = NULL;
}
//Q14 yha - tem atenção ao malloc
void appendL (LInt *l, int x){

    for(; *l; l = &(*l)->prox);
    *l = malloc(sizeof(LInt));
    (*l)->valor = x;
    (*l)->prox = NULL;
}
//Q15
void concatL (LInt *a, LInt b){
    for (; *a; a = &(*a)->prox);
    *a = b;
}
//Q16
LInt cloneL (LInt l){
    LInt result = malloc(sizeof(LInt));
    if(l == NULL) return NULL;
    result->valor = l->valor;
    result->prox = cloneL(l->prox);
    return result;
}
LInt cloneL2 (LInt l) {
    LInt list = NULL, temp = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = NULL;
        if(list == NULL) list = temp = new;
        else temp = temp->prox = new;
        l = l->prox;
    }
    return list;
}
//Q17
LInt cloneRev (LInt l){
    LInt list = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
        l = l->prox;
    }
    return list;
}
//Q18
int maximo (LInt l) {
    int max = l->valor, res;
    for(;l;l = l->prox) {
        if(l->valor > max) {
            max = l->valor;
        }
    }
    return max;
}
//Q19
int take (int n, LInt *l){
    int count = 0;
    for(; *l && n > 0; l = &(*l)->prox, n--, count++);
    while(*l){
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
    }
    return count;
}
//Q20
int drop (int n, LInt *l){
    int count = 0;
    for(; *l && n > 0; count++, n--) {
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
    }
    return count;
}
//Q21
LInt NForward (LInt l, int N){

    for(; N > 0; l = l->prox, N--);

    return l;
}
//Q22
int listToArray (LInt l, int v[], int N){
    int i, count = 0;
    for(i = 0; l && i<N; i++, l = l->prox) {
        v[i] = l->valor;
        count++;
    }

    return count;
}
//Q23
LInt arrayToList (int v[], int N){
    if(N == 0) return NULL;
    LInt new = malloc(sizeof(LInt));
    new->valor = (*v);
    new->prox = arrayToList(v + 1, N - 1);
    return new;
}
//Q24
LInt somasAcL (LInt l) {
    int sum = 0;
    LInt list = NULL, temp = NULL;
    for(;l; l = l->prox) {
        sum += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = sum;
        new->prox = NULL;
        if(!list) list = temp = new;
        else temp = temp->prox = new;
    }
    return list;
}
//Q25
void remreps (LInt l){
    for(; l; l = l->prox) {
        LInt *c = &(l->prox);
    while (*c && (*c)->valor == l->valor)
    {
        LInt temp = *c;
        *c = (*c)->prox;
        free(temp);
    }
    } 
}
//Q26
LInt rotateL (LInt l){
    LInt head = l;
    if(l && l->prox) {
        LInt aux = l;
        l = head = l->prox;
    for(;l && l->prox; l = l->prox);
    l->prox = aux;
    aux->prox = NULL;
    }
    return head;
}
//Q27
LInt parte (LInt l){
    if(!l || !l->prox) return NULL;
    LInt newL = l->prox;
    l->prox = l->prox->prox;    
    newL->prox = parte(l->prox);
    return newL;
}

LInt parte2 (LInt l){
    LInt head, *p = &head, *i = &l;
    int j;
    for (j = 1; *i; j++) {
        if (!(j%2)) {
            *p = *i;
            *i = (*i)->prox;
            p = &(*p)->prox;
           
        }
        else 
            i = &(*i)->prox;
    }
    *p = NULL;
    return head;
}
//Q28
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;} *ABin;


int altura (ABin a){
    int res;

    if(!a) return 0;
    int e = altura(a->esq);
    int d = altura(a->dir);

    if(e > d) res = e + 1;
    else res = d + 1;

	return res;
}
//Q29 facil i guess
ABin cloneAB (ABin a){
    if(a == NULL) return NULL;
    ABin b;
    b = malloc(sizeof(ABin));
    b->valor = a->valor;
    b->esq = cloneAB(a->esq); 
    b->dir = cloneAB(a->dir);  

    return b;
}
//Q30
void mirror (ABin *a) {
    if((*a)) {
        ABin temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&((*a)->esq));
        mirror(&((*a)->dir));
    }
}
//Q31 VER MELHOR
void inorder (ABin a, LInt * l) {
    if(a != NULL) {
        inorder(a->esq, l);
    while(*l)
        l = &(*l)->prox;
    *l = malloc(sizeof(LInt));
    (*l)->valor = a->valor;
    inorder(a->dir, &(*l)->prox);      
    } else *l = NULL;
}
//Q32 VER MELHOR
void preorder (ABin a, LInt * l) {
    if(a != NULL) {
        *l = malloc(sizeof(LInt));
        (*l)->valor = a->valor;
        preorder(a->esq, &(*l)->prox);
        while(*l)
            l = &(*l)->prox;
        preorder(a->dir, l);       
    } else *l = NULL;
}
//Q33
 void posorder (ABin a, LInt * l) {
    if(a != NULL) {
	posorder(a->esq, l);
	while(*l)
		l = &(*l)->prox;
	posorder(a->dir, l);
	while(*l)
	  l = &(*l)->prox;
	*l = malloc(sizeof(LInt);
	(*l)->valor = a->valor;
(*l)->prox = NULL;
	} else *l = NULL;
}
//Q34 
int depth (ABin a, int x) {
    if(!a) return -1;
    if(a->valor == x) return 1;

    int esq = depth(a->esq, x);
    int dir = depth(a->dir, x);
    if(esq == -1 && dir == -1)
        return -1;
    if(esq == -1 || (esq != -1 && dir != -1 && dir < esq))
        return 1 + dir;     
    return 1 + esq;
}
//Q35 facil
int freeAB (ABin a) {
    int count = 0;

    if(a) {
        count += 1 + freeAB(a->esq) + freeAB(a->dir);
        free(a);
    }

    return count;
}
//Q36 
 int pruneAB (ABin *a, int l) {
    int count = 0;

    if(*a && l == 0) {
        count += 1 + pruneAB(&(*a)->esq, 0) + pruneAB(&(*a)->dir, 0);
        free(*a);
        *a = NULL;
    } else if(*a)
        count += pruneAB(&(*a)->esq, l-1) + pruneAB(&(*a)->dir, l-1);
    
    return count;
 }
//Q37
int iguaisAB (ABin a, ABin b) {
    int ret = 1;
    if(a && b) {
       ret = b->valor == a->valor && iguaisAB(a->dir, b->dir) && iguaisAB(a->esq, b->esq);
    } else if((a == NULL && b != NULL) || (a != NULL && b == NULL)) ret = 0;
    return ret;
}
//Q38
LInt concat(LInt a, LInt b) {
    if(a == NULL) return b;
    LInt temp = a;
    while(temp->prox != NULL) temp = temp->prox;
    temp->prox = b;
    return a;
}
LInt nivelL (ABin a, int n) {
    if(a == NULL || n < 1) return NULL;
    if(n == 1) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    else return concat(nivelL(a->esq,n - 1),nivelL(a->dir,n - 1));
} 
//Q39
int nivelV (ABin a, int n, int v[]) {
    if(a == NULL || n < 1) return 0;
    if(n == 1) {
        *v = a->valor;
        return 1;
    } else {
        int e = nivelV(a->esq, n - 1, v);
        int d = nivelV(a->dir, n - 1, v+e);
        return e + d;
    }
}
//Q40
int dumpAbin (ABin a, int v[], int N) {
    if(a == NULL || N < 0) {
        return 0;
    }
    int esq = dumpAbin(a->esq, v, N);
    if(esq < N) {
        v[esq] = a->valor;
        return esq + 1 + dumpAbin(a->dir, v+esq+1, N-esq-1);
    } else return N;
}
//Q41
ABin somasAcA (ABin a) {
    if(a == NULL) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);
    new->valor = a->valor + (new->esq ? new->esq->valor : 0) + (new->dir ? new->dir->valor : 0);
    return new;
}
//Q42
int contaFolhas (ABin a) {
    int folhas = 0;
    if(a == NULL) return 0;
    if(a->esq == NULL && a->dir == NULL) {
        folhas++;
    } else {
        int esq = contaFolhas(a->esq);
        int dir = contaFolhas(a->dir);
        folhas += esq + dir;
    }
    return folhas;
}
//ou
int contaFolhas (ABin a) {
    if (a == NULL)
        return 0;
    
    return (!(a->esq) && !(a->dir)) + contaFolhas(a->esq) + contaFolhas(a->dir);
}
//Q43
ABin cloneMirror (ABin a) {
    if(!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneMirror(a->dir);
    new->dir = cloneMirror(a->esq);
    return new;
}
//Q44
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
//Q45
int lookupAB (ABin a, int x) {
    while(a) {
        if(a->valor == x) return 1;
        if(x < a->valor) a = a->esq;
        else a = a->dir;
    }
    return 0;
}
//Q46
int depthOrd (ABin a, int x) {
    int nivel = 0, existe = 0;
    while(a && existe == 0) {
        nivel++;
        if(x < a->valor) {
            a = a->esq;
        } else if(x > a->valor){
            a = a->dir;
        } else existe = 1;
    }
    return (existe ? nivel : -1);
}
//Q47
int maiorAB (ABin a) {
    if(a == NULL) return 0;
    while(a) {
        if(a->dir == NULL) return a->valor;
        else a = a->dir;
    }
}
//Q48
void removeMaiorA (ABin *a) {
    if((*a)->dir == NULL) {
        ABin temp = (*a);
        free(*a);
        (*a) = temp->esq;
    } else {
        removeMaiorA(&((*a)->dir));
    }
}
//Q49
int quantosMaiores (ABin a, int x) {
    if(a == NULL) return 0;

    if(a->valor <= x) return quantosMaiores(a->dir, x);
    else return 1 + quantosMaiores(a->esq, x) + quantosMaiores(a->dir, x);
}

//Q50
void listToBTree (LInt l, ABin *a) {
    if(l == NULL) return;
    ABin new = malloc(sizeof(struct nodo));
    int meio = length(l) / 2;
    LInt temp = l, prev = NULL;
    int i;
    for(i = 0; i < meio; i++) {
        prev = temp;
        temp = temp->prox;
    }
    new->valor = temp->valor;
    new->esq = new->dir = NULL;
    if(prev) prev->prox = NULL;
    
    if(l != temp) listToBTree(l,&(new->esq));
    if(temp->prox) listToBTree(temp->prox,&(new->dir));
    (*a) = new;
}
//Q51
int deProcuraAux(ABin a, int x, int maior) {
    if(a == NULL) return 1;
    if((maior && a->valor < x) || (!maior && a->valor > x)) return 0;
    return deProcuraAux(a->esq, x, maior) && deProcuraAux(a->dir, x, maior);
}


int deProcura (ABin a) {
    if(a == NULL) return 1;
    int e = deProcuraAux(a->esq, a->valor, 0) && deProcura(a->esq);
    int d = deProcuraAux(a->dir, a->valor, 1) && deProcura(a->dir);
    return e && d;
}






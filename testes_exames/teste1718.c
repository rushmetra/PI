#include <stdio.h>
#include <stdlib.h>

//Parte A - COMEÇA AQUI

typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

//Ex1 
int retiraNeg(int v[], int N) {
    int i, j;
    for(i = 0; i < N; i++) {
        if(v[i] < 0) {
            for(j = i; j < N; j++) {
                v[j] = v[j+1];
            }
            N--;
            i--;
        }
    }
    return N;
}
//Ex2
int ocorreu(char s[], int j, int n) {
    int i, ans = 0;
    for (i = j; i < n && !ans; i++)
        ans = s[i] == s[n];
    return ans;
}

int difConsecutivos(char s[]) {
    int i, j,count = 0, max = 0, flag = 1;
    for (i = 0; s[i]; i++, count = 0, flag = 1) {
        for (j = i; s[j] && flag; j++) {
            if (!ocorreu(s, i, j))
                count++;
            else 
                flag = 0;
        }
        if (count > max)
            max = count;
    }
    return max;
}

int maximo (LInt l) {
    int max, r;
    while(l) {
        if(l->valor > r) r = l->valor;
        l = l->prox;
    }
  
    return r;
}

int removeAll (LInt *l, int x) {
    int count;
    while(*l) {
        if((*l)->valor == x) {
            (*l) = (*l)->prox;
            count++;
        } else l = &((*l)->prox);
    }
    return count;
}

LInt arrayToList (int v[], int N){
    if(N == 0) return NULL;
    LInt new = malloc(sizeof(struct slist));
    new->valor = (*v);
    new->prox = arrayToList(v + 1, N - 1);
    return new;
}
//Parte B

//ex 1
int minheapOK (ABin a) {
    if(!a) return 1;
    int l, r;
    l = a->esq ? minheapOK(a->esq) && a->valor < a->esq->valor : 1;
    r = a->dir ? minheapOK(a->dir) && a->valor < a->dir->valor : 1;
    return l && r;
}
//ex 2
int maxHeap (ABin a) {
    if(!a) return 0;
    int l = maxHeap(a->esq);
    int r = maxHeap(a->dir);

    if(l != 0 || r != 0) {
        if(l > r) return l;
        else return r;
    } else return a->valor;
}

void removeMin (ABin *a) {
    if(!(*a)->esq) {
        ABin temp = (*a);
        (*a) = temp->dir;
        free(temp);
    } else if(!(*a)->dir) {
        ABin temp = (*a);
        (*a) = temp->esq;
        free(temp);
    } else if((*a)->esq->valor < (*a)->dir->valor) {
        (*a)->valor = (*a)->esq->valor;
        removeMin(&((*a)->esq));
    } else {
        (*a)->valor = (*a)->dir->valor;
        removeMin(&((*a)->esq));
    }
}

void heapSort (int v[], int N) {
    ABin *tree = malloc(sizeof(ABin));
    *tree = NULL;
    for(int i = 0; i < N; i++) add(tree,v[i]);
    for(int i = 0; i < N; i++) {
        v[i] = (*tree)->valor;
        removeMin(tree);
    }
}













ABin getBTree() {
    ABin new = malloc(sizeof(struct nodo));
    int num;
    printf("Valor central: ");
    scanf("%d",&num);
    new->valor = num;
    printf("(%d) Valor à esquerda? (0 - não ; 1 - sim) ", new->valor);
    scanf("%d",&num);
    if(num) new->esq = getBTree();
    else new->esq = NULL;
    printf("(%d) Valor à direita? (0 - não ; 1 - sim) ", new->valor);
    scanf("%d",&num);
    if(num) new->dir = getBTree();
    else new->dir = NULL;
    return new;
}

void printBTreeUtil(ABin root, int space) { 
    if (root == NULL) return; 
  
    space += 3; 
  
    printBTreeUtil(root->dir, space); 

    int i;
    for (i = 3; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->valor); 
  
    printBTreeUtil(root->esq, space); 
} 
  
void printBTree(ABin root) { 
   printBTreeUtil(root, 0); 
} 

int main() {
    ABin tree = getBTree();
    printBTree(tree);
    //add(&tree,50);
    //printBTree(tree);
    ABin *aux = &tree;
    removeMin(aux);
    printBTree(*aux);
    return 0;
}
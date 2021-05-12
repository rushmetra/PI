#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Static queues 

// nossa nossa assim voce me mata
// ai se eu te pego ai se te pego

// pos = (front + length) % Max
void SinitQueue (SQueue q){
    q->front = 0;
    q->length = 0;
}

int  SisEmptyQ (SQueue q){ // a queue pode estar vazia e ter a front no indice 2 por exemplo
	return q->length == 0;
}

int  Senqueue (SQueue q, int x){
	int r = 0;
    if(q->length == Max) r = 1;
    else {
        int pos = (q->front + q->length) % Max;
        q->values[pos] = x;
        q->length++;
    }
    return r;
}

int  Sdequeue (SQueue q, int *x) {
	int r = 0;
    if(SisEmptyQ(q)) r = 1;
    else {
        *x = q->values[q->front];
        q->length--;
        q->front = (q->front + 1) % Max;
    }
	return r;
}

int  Sfront (SQueue q, int *x) {
	int r = 0;
    if(SisEmptyQ(q)) r = 1;
    else {
        *x = q->values[q->front];
    }
	return r;
}

// shift + delete -> apaga a linha toda
// fn + end -> fim da linha
// ctrl + end -> fim da palavra 
// vice-verse com home ^
// ctrl + z -> voltar pra trás

void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}

// Queues with dynamic arrays

int dupQueue (DQueue q) {
	// ...
	return (-1);
}

void DinitQueue (DQueue q) {
	// ...
}

int  DisEmptyQ (DQueue s) {
	return (-1);
}

int  Denqueue (DQueue q, int x){
	// ...
	return (-1);
}

int  Ddequeue (DQueue q, int *x){
	// ...
	return (-1);
}

int  Dfront (DQueue q, int *x){
	// ...
	return (-1);
}

void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}
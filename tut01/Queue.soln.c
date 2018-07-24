#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

#define CIRCULAR

void initQueue(Queue *q) {
    q->nitems = 0;
    q->head = 0;
    q->tail = 0;
}

void enterQueue(Queue *q, int value) {
    // TODO
    q->items[q->tail] = value;
    q->tail++;
#ifdef CIRCULAR
    q->tail = q->tail % MAXQ;
#endif
    q->nitems++;
}

int leaveQueue(Queue *q) {
    // TODO
#ifdef CIRCULAR
    int res = q->items[q->head];
    q->head++;
    q->head = q->head % MAXQ;
    q->nitems--;
    return res;
#else
    int res = q->items[q->head];
    q->tail--;
    q->nitems--;
    for (int i = 0; i < q->tail; i++) {
        q->items[i] = q->items[i+1];
    }
#endif
}

int lengthQueue(Queue q) {
    return q.nitems;
}

void showQueue(Queue q) {
    // TODO
    for (int i = q.head; i != q.tail; i = (i + 1) % MAXQ) {
        printf("%d ", q.items[i]);
    }
    printf("\n");
}

int main(void) {
    Queue *q = malloc(sizeof(Queue));
    initQueue(q);

    int sequence[10] = {
        5, 7, 3, 4, -1, -1, 6, 1, -1, 9};

    for (int i = 0; i < 10; i++) {
        if (sequence[i] > 0) {
            enterQueue(q, sequence[i]);
        } else {
            leaveQueue(q);
        }
        showQueue(*q);
    }
}

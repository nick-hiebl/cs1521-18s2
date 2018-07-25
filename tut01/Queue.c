#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

void initQueue(Queue *q) {
    q->nitems = 0;
    q->head = 0;
    q->tail = 0;
}

void enterQueue(Queue *q, int value) {
    // TODO
    q->items[q->tail] = value;
    q->tail++;
    q->nitems++;
}

int leaveQueue(Queue *q) {
    // TODO
    int out = q->items[q->head];
    q->tail--;
    for (int i = 0; i < q->tail; i++) {
        q->items[i] = q->items[i+1];
    }
    q->nitems--;
    return out;
}

int lengthQueue(Queue q) {
    return q.nitems;
}

void showQueue(Queue q) {
    // TODO
    for (int i = 0; i != q.tail; i++) {
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

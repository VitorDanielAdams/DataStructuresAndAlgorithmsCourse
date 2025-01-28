#include <stdbool.h>
#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int head;
    int tail;
} Queue;

void printEmptyQueue() {
    printf("Queue is empty\n");
}

void initializeQueue(Queue* q)
{
    q->head = -1;
    q->tail = 0;
}

bool isEmpty(Queue* q) { 
    return (q->head == q->tail - 1); 
}

bool isFull(Queue* q) { 
    return (q->tail == MAX_SIZE); 
}

int size(Queue* q) {
    int size = q->tail - q->head - 1;
    printf("Queue size: %d \n", size);
    return size;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printEmptyQueue();
        return -1;            
    }
    return q->items[q->head + 1];
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->items[q->tail] = value;
    q->tail++;
    printf("Add %d to Queue\n", value);
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printEmptyQueue();
        return;
    }
    printf("Remove %d to Queue\n", q->items[q->head+1]);
    q->head++;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printEmptyQueue();
        return;
    }

    printf("Current Queue: ");
    for (int i = q->head + 1; i < q->tail; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main()
{
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);

    printf("peek element: %d\n", peek(&q));
    printQueue(&q);
    size(&q);

    dequeue(&q);
    printQueue(&q);
    size(&q);

    return 0;
}
#include "stdlib.h"
#include "stdio.h"

#define MAX 10

struct deque
{
    int arr[MAX];
    int front;
    int rear;
};

struct deque *initialiseDeque()
{

    struct deque *deque = malloc(sizeof(struct deque));

    deque->front = -1;
    deque->rear = -1;
    return deque;
}

int isEmpty(struct deque *deque)
{

    return deque->front == -1;
}

int isFull(struct deque *deque)
{

    return deque->front == (deque->rear + 1) % MAX;
}

void insertFront(struct deque *deque, int value)
{

    if (isFull(deque))
    {
        printf("error, queue is full\n");

        return;
    }

    if (deque->front == -1)
    {
        deque->front = 0;
        deque->rear = 0;

        deque->arr[deque->front] = value;
    }

    else
    {

        deque->front = (deque->front - 1 + MAX) % MAX;
        deque->arr[deque->front] = value;
    }
}

void insertRear(struct deque *deque, int value)
{

    if (isFull(deque))
    {
        printf("error, deque is full\n");
        return;
    }

    if (deque->front == -1)
    {
        deque->front = 0;
        deque->rear = 0;

        deque->arr[deque->rear] = value;
    }

    else
    {
        deque->rear = (deque->rear - 1 + MAX) % MAX;
        deque->arr[deque->rear] = value;
    }
}

void deleteFront(struct deque *deque)
{

    if (isEmpty(deque))
    {
        printf("deque is empty\n");
        return;
    }

    int element = deque->arr[deque->front];

    // last element
    if (deque->front == deque->rear)
    {
        deque->front = -1;
        deque->rear = -1;
    }

    else
    {

        deque->front = (deque->front + 1) % MAX;
    }
}

void deleteRear(struct deque *deque)
{

    if (isEmpty(deque))
    {
        printf("deque is empty\n");
        return;
    }

    int element = deque->arr[deque->rear];

    // last element
    if (deque->front == deque->rear)
    {
        deque->front = -1;
        deque->rear = -1;
    }

    else
    {

        deque->rear = (deque->rear - 1 + MAX) % MAX;
    }
}
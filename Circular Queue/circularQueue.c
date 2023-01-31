#include "stdio.h"
#include "stdlib.h"

#define MAX 5

struct queueContainer
{
    int queue[MAX];
    int top;
    int rear;
};

void enqueue(struct queueContainer *queue, int item);
void dequeue(struct queueContainer *queue);
void peek(struct queueContainer *queue);
void printQueue(struct queueContainer *queue);
int isFull(struct queueContainer *queue);
int main(int argc, char **argv)
{

    struct queueContainer *queue = malloc(sizeof(struct queueContainer));

    // initialise queue pointers
    queue->top = -1;
    queue->rear = -1;

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);

    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 7);
}

void enqueue(struct queueContainer *queue, int item)
{

    // check if full
    if (isFull(queue))
    {

        printf("Error, Queue is full\n");
        return;
    }

    if (queue->top == -1)
        queue->top = 0;

    queue->rear = (queue->rear + 1) % MAX;

    queue->queue[queue->rear] = item;
}

void dequeue(struct queueContainer *queue)
{

    // check if empty
    if (queue->top == -1)
    {
        printf("Error, the queue is empty\n");
        return;
    }

    else
    {
        // check if front has wrapped around
        // printf("dequeue %d\n", queue->queue[queue->top]);
        queue->top = (queue->top + 1) % MAX;

        // last item in queue reset Top and rear
        if (queue->top == queue->rear)
        {
            queue->top = -1;
            queue->rear = -1;
        }
    }
}

void peek(struct queueContainer *queue)
{

    printf("Next Item is %d \n", queue->queue[queue->top]);
}

void printQueue(struct queueContainer *queue)
{
    int i;
    for (i = queue->top; i != queue->rear; i = (1 + i) % MAX)
    {

        printf("%d\n", queue->queue[i]);
    }
    printf("%d\n", queue->queue[i]);
}

int isFull(struct queueContainer *queue)
{
    // if rear is just behind front or front and rear occupied
    if (queue->rear + 1 == queue->top || (queue->top == 0 && queue->rear == MAX - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
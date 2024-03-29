#include "stdio.h"
#include "stdlib.h"

#define MAX 10

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
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);

    printQueue(queue);

    dequeue(queue);

    printQueue(queue);

    peek(queue);
}

void enqueue(struct queueContainer *queue, int item)
{

    // check if full
    if (queue->rear == MAX - 1)
    {

        printf("Error, Queue is full\n");
        return;
    }

    // first item, set top 0 and rear + 1
    if (queue->top == -1)
    {

        queue->top = 0;
        queue->rear++;
        queue->queue[queue->rear] = item;
    }

    else
    {

        queue->rear++;
        queue->queue[queue->rear] = item;
    }
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
        queue->top++;
        // last item in queue reset Top and rear
        if (queue->top > queue->rear)
        {
            queue->top, queue->rear = -1;
        }
    }
}

void peek(struct queueContainer *queue)
{

    printf("Next Item is %d \n", queue->queue[queue->top]);
}

void printQueue(struct queueContainer *queue)
{
    if (queue->top == -1)
    {
        printf("QUEUE is empty\n");
        return;
    }
    for (int i = queue->top; i <= queue->rear; i++)
    {

        printf("%d\n", queue->queue[i]);
    }
}

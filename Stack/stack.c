#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define MAX 10

typedef struct stack {
    int items[MAX];
    int top;
} stack;



void push (stack* stack, int item);
void printStack(stack* stack);
void pop (stack*stack);
int isEmpty(stack* stack);
int isFull(stack* stack);
void checkTop(stack* stack);


void printStack(stack* stack){

    int size = stack->top;
    printf("TOP IS %d\n",stack->top);
    for(int i = 0; i <=size; i++){

        printf("%d\n", i);

    };
}
void push (stack* stack, int item){

    if (isFull(stack)){
        printf("ERROR, stack is full.\n");
    }
    else{
        stack->items[++stack->top] = item;
    }

}

void pop (stack*stack){

    if(isEmpty(stack)){
        printf("ERROR, stack is empty");

    }
    else{

        stack->top--;
    }
}

int isEmpty(stack* stack){

    if(stack->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


int isFull(stack* stack){

    if(stack->top == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

void checkTop(stack* stack){

    if(!isEmpty){
        printf("Top Element is: %d", stack->items[stack->top]);
    }
}


int main (int argc, char** argv){

    stack* stack = malloc(sizeof(stack));
    stack->top =-1;

    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);

    printStack(stack);

    pop(stack);

    printStack(stack);


}

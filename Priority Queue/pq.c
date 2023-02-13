#include "stdio.h"
#include "stdlib.h"

#define MAXIMUM 10

int size = 0;
void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int i)
{

    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < size && arr[leftChild] > arr[i])
    {
        largest = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (i != largest)
    {
        swap(&arr[i], &arr[largest]);

        for (int j = size / 2 - 1; j >= 0; j--)
        {
            heapify(arr, j);
        }
    }
}

void insert(int arr[], int value)
{

    if (size == 0)
    {
        arr[0] = value;
        size++;
    }

    else
    {

        if (size == MAXIMUM - 1)
        {
            printf("Error PQ full\n");
            return;
        }

        arr[size] = value;
        size += 1;

        for (int i = size / 2 - 1; i >= 0; i--)
        {

            heapify(arr, i);
        }
    }
}

void deleteValue(int arr[], int value)
{

    int x = 1;
    int i;
    for (i = 0; i <= size; i++)
    {

        if (arr[i] == value)
        {
            x = value;
            break;
        }
    }

    swap(&arr[size - 1], &arr[i]);

    size--;

    for (i = size / 2 - 1; i >= 0; i--)
    {

        heapify(arr, i);
    }
}

void deleteMax(int arr[])
{

    if (size == 0)
    {
        printf("error, heap is empty\n");
        return;
    }

    swap(&arr[0], &arr[size - 1]);

    size--;

    for (int i = size / 2 - 1; i >= 0; i--)
    {

        heapify(arr, i);
    }
}

void printArray(int array[])
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    int array[10];

    insert(array, 3);
    printf("size: %d\n", size);
    insert(array, 4);

    insert(array, 9);
    insert(array, 5);
    insert(array, 2);

    printf("Max-Heap array: ");
    printArray(array);

    deleteMax(array);

    printf("After deleting an element: ");

    printArray(array);
}
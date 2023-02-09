#include "stdlib.h"
#include "stdio.h"

#define MAXIMUM 10

int size = 0;
void swap(int *largest, int *current);
void heapify(int arr[], int i)
{
    if (size == 0)
    {
        return;
    }
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

    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);

        heapify(arr, largest);
    }
}

void swap(int *largest, int *current)
{

    int temp = *current;
    *current = *largest;
    *largest = temp;
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
        if (size < MAXIMUM - 1)
        {

            arr[size++] = value;

            for (int i = size / 2 - 1; i >= 0; i--)
            {
                heapify(arr, i);
            }
        }
    }
}

void deleteMax(int arr[])
{

    if (size == 0)
    {
        printf("Error, heap is empty\n");
        return;
    }

    printf("removing the Max element, %d\n", arr[0]);

    arr[0] = arr[size];
    size--;

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int array[10];

    insert(array, 3);

    insert(array, 4);

    insert(array, 9);

    insert(array, 5);

    insert(array, 2);

    // printf("Max-Heap array: ");
    printArray(array, size);

    // printf("After deleting an element: ");

    // printArray(array, size);
}
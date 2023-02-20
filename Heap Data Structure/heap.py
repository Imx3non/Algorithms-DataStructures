def heapify(array, size, i):

    largest = i
    leftChild = 2*i + 1
    rightChild = 2*i + 2

    if (leftChild < size and array[i] < array[leftChild]):
        largest = leftChild
    if (rightChild < size and array[largest] < array[rightChild]):
        largest = rightChild

    if (largest != i):

        array[i], array[largest] = array[largest], array[i]

        heapify(array, size, largest)


def insert(arr, value):

    size = len(arr)
    if (size == 0):
        arr.append(value)
    else:
        arr.append(value)
        size += 1
        # heapify from bottom to top
        for i in range((size//2) - 1, -1, -1):

            heapify(arr, size, i)


def removeMax(arr: list):

    size = len(arr)
    if (size == 0):
        print("error heap is empty")

    # swap last and first element, remove last elemnt and heapify the array
    arr[0], arr[size-1] = arr[size - 1], arr[0]
    print("Popping " + arr[size - 1] + " from heap")
    arr.pop(arr[size - 1])

    for i in range((size//2), -1, -1):
        heapify(arr, len(arr), i)


arr = []

insert(arr, 3)
insert(arr, 4)
insert(arr, 9)
insert(arr, 5)
insert(arr, 2)

print(str(arr))

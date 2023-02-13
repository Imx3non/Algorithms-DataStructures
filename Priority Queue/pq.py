def heapify(arr, size, i):

    if size == 1:
        return
    largest = i
    leftChild = 2*i + 1
    rightChild = 2*i+2

    if (leftChild < size and arr[leftChild] > arr[i]):
        largest = leftChild

    if (rightChild < size and arr[rightChild] > arr[largest]):
        largest = rightChild

    if (i != largest):

        arr[i], arr[largest] = arr[largest], arr[i]
        for i in range(size // 2 - 1, -1, -1):
            heapify(arr, size, i)


def insert(arr, value):

    size = len(arr)

    if (size == 0):
        arr.append(value)

    else:
        arr.append(value)
        size += 1

        for i in range(size // 2 - 1, -1, -1):
            heapify(arr, size, i)


def deleteValue(arr: list, value):

    for i in arr:
        if i == value:
            break

    arr.pop(i)

    size = len(arr)
    for i in range(size // 2, -1, -1):
        heapify(arr, size, i)


def deleteMax(arr: list):

    size = len(arr)

    arr[size-1], arr[0] = arr[0], arr[size-1]

    arr.pop(size-1)
    size -= 1
    for i in range(size // 2, -1, -1):
        heapify(arr, size, i)


arr = []

insert(arr, 3)
insert(arr, 4)
insert(arr, 9)
insert(arr, 5)
insert(arr, 2)

print("Max-Heap array: " + str(arr))

deleteValue(arr, 4)
print("After deleting an element: " + str(arr))

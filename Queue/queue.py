class Queue:

    def __init__(self):

        self.queue = []

    def enqueue(self, item):

        self.queue.append(item)

    def dequeue(self, item):

        if (len(self.queue < 1)):
            print("Error Queue is empty")
        else:
            self.queue.pop(0)

    def printQueue(self):

        for item in self.queue:
            print(item)

    def peek(self):
        print(self.queue[0])

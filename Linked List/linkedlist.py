import copy


class LinkedList:

    def __init__(self, value=None, next=None):

        self.value = value
        self.next = next

    def addNode(self, value):

        newNode = LinkedList(value)

        temp = copy.deepcopy(self)
        self.value = value
        self.next = temp

    def delete(self, value):
        if self.value == None:
            print("Error list is empty")
            return

        if (self.next != None and self.value == value):

            self.value = self.next.value
            self.next = self.next.next
            return

        temp = self
        prev = self
        while (temp != None and temp.value != value):

            prev = temp
            temp = temp.next

        if (temp == None):
            print("Error, value not found")
            return

        prev.next = temp.next

    def traverse(self):

        current = self
        if (current.value == None):
            print("Error, list is empty")

        while current.next != None:

            print(current.value)
            current = current.next


linked = LinkedList()

linked.addNode(1)


linked.traverse()

linked.delete(1)
print("\n")

linked.traverse()

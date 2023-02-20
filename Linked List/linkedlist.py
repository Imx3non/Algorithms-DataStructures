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

        elif self.value == value:

            if self.next != None:

                self.value = self.next.value
                self.next = self.next.next
            else:
                self.value = None
                self.next = None

        else:
            current = self.next
            prev = self
            while current != None:
                if current.value == value:
                    prev.next = current.next
                    break
                prev = current
                current = current.next

    def traverse(self):

        current = self

        while current.next != None:

            print(current.value)
            current = current.next


linked = LinkedList()

linked.addNode(1)
linked.addNode(2)
linked.addNode(3)
linked.addNode(4)

linked.traverse()

linked.delete(1)
print("\n")

linked.traverse()

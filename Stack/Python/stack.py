class Stack:

    def __init__(self):

        self.stack = []
        self.top = -1
    
    def push(self,item):

        self.stack.append(item)
        self.top += 1
    
    def pop(self):

        if(self.top == -1):
            print("Error, Stack is empty")
        else:
            self.stack.pop()
            self.top -=1

    def checkTop(self):
        return self.stack[self.top]

    def printStack(self):

        for i in self.stack:
            print(i)
        
        print ("\n")
        



stack = Stack()

stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)

stack.printStack()

stack.pop()

stack.printStack()

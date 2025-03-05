print( "Hello linkedlist")

class Node:
    def __init__(self, data):
        #data part of Node
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def insertAtBegin(self, value):
        newNode = Node(value)
        self.size += 1
        if self.head is None:
            self.head = newNode
            return
        else:
            tempNode = self.head
            self.head = newNode
            self.head.next = tempNode
    
    def insertAtIndex(self, index, value):
        if index < 0 or index > self.size:
            print("Invalid Index")
            return
        if index == 0:
            self.insertAtBegin(value)
            return
        else:
            newNode = Node(value)
            item = self.head
            for i in range(index-1):
                item = item.next
            behindNode = item.next
            item.next = newNode
            newNode.next = behindNode
            self.size += 1

    def printList(self):
        # interate through the list
        item = self.head
        while item is not None:
            print(item.data)
            item = item.next
    def append(self, value):
        newNode = Node(value)
        if (self.head == None):
            self.head = newNode
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = newNode
        self.size += 1
        pass

    def deleteAtBegin(self):
        if self.head is None:
            print("List is empty")
            return
        else:
            self.head = self.head.next
            self.size -= 1
        pass
    def deleteAtEnd(self):
        if self.head is None:
            print("lis is empty")
        elif self.size == 1:
            self.head = None
            self.size -= 1
        else:
            temp = self.head
            while temp.next.next is not None:
                temp = temp.next
            temp.next = None
            self.size -= 1
        pass
    
    def deleteAtIndex(self, index):
        if index < 0 or index >= self.size:
            print("Invalid Index")
            return
        if index == 0:
            self.deleteAtBegin()
            return
        if index == (self.size -1):
            self.deleteAtEnd()
            return
        
        item = self.head
        for i in range(index-1):
            item = item.next  
        item.next = item.next.next
        self.size -= 1
        pass

    def circle(self):
        item = self.head
        while item.next is not None:
            item = item.next
        
        item.next = self.head
        pass
        
        

List = LinkedList()
List.insertAtBegin(1)
List.insertAtBegin(2)
List.insertAtBegin(3)
List.insertAtIndex(3, 4)
List.insertAtIndex(0, -1)
List.append(123)
List.printList()
# List.deleteAtBegin()
# List.printList()
# List.deleteAtEnd()
# print("delete at begin")
# List.printList()

List.deleteAtIndex(3)
List.circle()
List.printList()






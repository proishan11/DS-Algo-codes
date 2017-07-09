''' Linked List Implementation
	Operations: insertion,deletion,print'''

class Node:
	def __init__(self,value):
		self.key = value
		self.next = None

class linkedList:
	def __init__(self):
		self.head = None

	def printlist(self):
		temp = self.head
		while(temp):
			print(temp.key)
			temp = temp.next

	def insert_begining(self,node):
		'''Insertion at begining'''
		temp = self.head
		node.next = self.head
		self.head = node

	def insert_end(self,node):
		'''Insertion at end'''

		temp = self.head
		while(temp.next):
			temp = temp.next
		temp.next = node
		node.next = None

	def insert(self,node,position):
		'''Insert any node at certain position.
			Args:
				node : node to be inserted
				position : desired position at which the node
							is to be inserted.
		'''
		temp = self.head
		if(position == 1):
			node.next = self.head
			self.head = node
		else :
			for i in range(position-2):
				temp = temp.next
			node.next = temp.next
			temp.next = node

	def delete(self,position=None,key=None):
		'''Delete any node.
			Args:
				position : position of the node in index 1
				key : value present in the node
		'''
		temp = self.head
		if(position is not None):
			if self.head == None:
				return
			for i in range(position-1):
				temp = temp.next
				if(temp is None):
					break
			if(temp is None):
				return
			next_node = temp.next.next
			temp.next = None
			temp.next = next_node
		if(key is not None):
			if self.head is None:
				return
			while(temp):
				if(temp.next.key==key):
					break
				temp = temp.next
			next_node = temp.next.next
			temp.next = None
			temp.next = next_node

		

llist = linkedList()
first = Node(5)
second = Node(4)
third = Node(3)
llist.head = first
first.next = second
second.next = third
llist.insert_begining(Node(1))
llist.insert_end(Node(10))
llist.insert(Node(99),4)
llist.insert(Node(77),1)
print("Current list is")
llist.printlist()
llist.delete(position=3)
llist.delete(key=99)
print("list after deletion")
llist.printlist()
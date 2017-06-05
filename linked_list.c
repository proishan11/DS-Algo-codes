// Program to insert a node at the begining of a linked list.

#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *next;             //poiner variable next of type stuct node.
};
struct node *head = NULL;          //pointer variable head pointing to the first node of a linked list. 

void insert(int x){
	struct node* temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = head;
	head = temp;
}

void print(){
	struct node* temp;
	temp = head;
	printf("the list is\n");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main(){
	int n,x,i;
	printf("Enter the no. of numbers\n");
	scanf("%d",&n);
	printf("Enter the numbers\n");
	for(i=0; i<n; i++){
		scanf("%d",&x);
		insert(x);
		print();
	}
}
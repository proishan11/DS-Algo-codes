// Program to insert a node at the begining of a linked list.
/* In this program head is declared as a local variable of main() function thus we have to pass head as argument 
to other functions. */

#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *next;             //poiner variable next of type stuct node.
};

struct node *insert(struct node* head , int x){
	struct node* temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = head;
	head = temp;
	return head;
}

void insertn(struct node*head, int x, int p){
	struct node* temp;
	int i;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	for(i=1; i<p-1; i++){
		head = head->next;
	}
	temp->next = head->next;
	head->next = temp;

}

void print(struct node *head){
	printf("the list is\n");
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

void main(){
	struct node *head = NULL; 
	int n,x,i;
	printf("Enter the no. of numbers\n");
	scanf("%d",&n);
	printf("Enter the numbers\n");
	for(i=0; i<n; i++){
		scanf("%d",&x);
		head = insert(head,x);
		print(head);
	}
	insertn(head,58,3);
	print(head);
}
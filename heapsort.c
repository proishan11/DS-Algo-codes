#include<stdio.h>

void print_array(int a[],int n){
	for(int i=0; i<n; i++){
		
		printf("%d\n",a[i]);
	}
}

void swap(int* a, int * b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

//n equals size of heap i.e no. of elements in a heap.
void max_heapify(int a[], int n, int i){
	int left = 2*i+1;           //parent element
	int right = 2*i+2;			//second parent element
	int largest = i;
	if(left<n && a[largest]<a[left])
		largest = left;
	if(right<n && a[largest]<a[right])
		largest = right;
	if(largest!=i){
		swap(&a[i],&a[largest]);
		max_heapify(a,n,largest);  //recursively max_heapify the affected elements
	}
}

void heapsort(int a[], int n){
	for(int i=n/2-1; i>=0; i--)
		max_heapify(a,n,i);
	for(int i=n-1; i>=0; i--){      //extract_max process
		swap(&a[0],&a[i]);
		max_heapify(a,i,0);			//size of heap decreases by 1 in each iteration.
	}
}

void main(){
	int a[6]={12,11,13,5,6,7};
	printf("Curent array is\n");
	print_array(a,6);
	heapsort(a,6);
	printf("Array after sorting\n");
	print_array(a,6);
}
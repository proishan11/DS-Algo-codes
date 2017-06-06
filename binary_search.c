// An example of binary search.

#include<stdio.h>

int search(int a[7], int target){
	int min = 0; 
	int max = 6;
	int guess;
	while(min<=max){                  //when max<min no more elements are left to search therefore target is not present in array.
		guess = (min+max)/2;
		if(a[guess]==target)
			return guess;
		else if(a[guess]<target)
			min = guess+1;
		else
			max = guess-1;
	}
	return -1;
}

void main(){
	int x;
	int a[7]={1,2,3,4,5,6,7};		//sorted array. If array not sorted sort it first.
	x = search(a,6);
	printf("%d\n",x);              // prints the index of the target
}
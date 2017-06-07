#include<stdio.h>

void main(){
	int a[7],i,j,key;
	for(i=0; i<7; i++){
		scanf("%d",&a[i]);                  //Enter the value of array elements.
	}
	for(i=0; i<7; i++){
		printf("%d ",a[i]);                 //Prints array elements before sorting.
	}
	printf("\n");
	for(i=1; i<7; i++){                     //insertion.
		key = a[i];
		for(j=i-1; j>=0&&a[j]>key; j--){
			a[j+1] = a[j];	
		}
		a[j+1] = key;
	}
	for(i=0; i<7; i++){
		printf("%d ",a[i]);                 //print array elements after sorting.
	}
}
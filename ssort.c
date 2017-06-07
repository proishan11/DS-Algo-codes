#include<stdio.h>

int minIndex(int a[7], int i){
	int j,index=i;
	int minValue = a[i];
	for(j=index+1; j<7; j++){
		if(a[j]<minValue){
			index = j;
			minValue = a[j];                  //the problem was here. we have to also swap the min value to compare with other values.
		}
	}
	return index;
}

void swap(int* a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void main(){
	int a[7];
	int i,x;
	for(i=0; i<7; i++){
		scanf("%d",&a[i]);
	}
	for(i=0; i<7; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=0; i<7; i++){
		x = minIndex(a,i);
		swap(&a[x],&a[i]);
	}
	for(i=0; i<7; i++){
		printf("%d ",a[i]);
	}
}
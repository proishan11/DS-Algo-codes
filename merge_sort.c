#include<stdio.h>
#include<stdlib.h>

//print any array
void print_arr(int a[],int len){
	for(int i=0; i<len; i++){
		printf("%d\n",a[i]);
	}
}

//merge two subarrays
void merge(int a[],int p, int q, int r){
	int n1=q-p+1;
	int n2=r-q;
	int l1[n1], l2[n2];
	for(int i=0; i<n1; i++){
		l1[i]=a[p+i];
	}

	for(int i=0; i<n2; i++){
		l2[i]=a[q+i+1];
	}
	int k = p,i=0,j=0;
	while(i<n1 && j<n2){
		if(l1[i]<=l2[j]){
			a[k] = l1[i];
			i++;
		}
		else{
			a[k] = l2[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=l1[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=l2[j];
		j++;
		k++;
	}
}

void mergesort(int a[],int p,int r){
	if(p<r){
		int q = p+(r-p)/2;
		printf("q=%d\n",q);
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		//printf("ak\n");
		print_arr(a,8);
		merge(a,p,q,r);
	}
}



void main(){
	int a[8]={9,8,7,6,5,4,3,2};
	int p=0;
	int r=7;
	int len = r-p+1; 
	printf("Current array is:\n");
	print_arr(a,len);
	mergesort(a,p,r);
	printf("After sorting\n");
	print_arr(a,len);
}
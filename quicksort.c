#include<stdio.h>
void print_arr(int a[], int r){               //print each element of array
    for(int i=0; i<=r; i++){
        printf("%d\n",a[i]);
    }
}

void swap(int* a, int* b){
    int c;
    c = *a; 
    *a = *b;
    *b = c;
}

int partition(int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    for(int j=p; j<=r-1; j++){                  //j = p is crucial because in second call of quicksort q+1!=0
        if(a[j]<x){
            i+=1;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1;                                 
}

void quicksort(int a[], int p, int r){
    if(p<r){
        int q = partition(a,p,r);
        quicksort(a,p,q-1);               //recursively sort the arrays around pivot q.
        quicksort(a,q+1,r);
    }
}


void main(){
    int a[8]={2,8,7,1,3,5,6,4};
    int p=0,r=7;
    printf("Current array:\n");
    print_arr(a,r);
    quicksort(a,p,r);
    printf("Array after sorting:\n");
    print_arr(a,r);
}    
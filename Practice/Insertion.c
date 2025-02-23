#include<stdio.h>
#include<stdlib.h>

void insertionsort(int *a,int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0&&a[j]<a[j-1]){
            int temp=a[j];
           a[j]= a[j-1];
           a[j-1]=temp;
           j--;
        }
    }
}

void main(){
    int a[]={12,5,23,19,21};
    insertionsort(a,5);
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
}
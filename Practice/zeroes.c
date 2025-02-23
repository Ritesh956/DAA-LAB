#include<stdio.h>
#include<stdlib.h>
int c=0;

int maxele(int * a,int low,int high){
if(low>=high){
    return a[high];
}
int mid=(low+high)/2;
int left=maxele(a,low,mid);
int right=maxele(a,mid+1,high);

if(left==0){
    c++;
}
if(right==0){
    c++;
}

if(left<right){
    return right;
}
else{
        return left;
}
}

int minele(int * a,int low,int high){
if(low>=high){
    return a[high];
}
int mid=(low+high)/2;
int left=minele(a,low,mid);
int right=minele(a,mid+1,high);

if(left==0){
    c++;
}
else if(right==0){
    c++;
}


}




int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ele=maxele(a, 0, n - 1);


  printf("%d ",ele);

printf("%d ",c);

    return 0;
}
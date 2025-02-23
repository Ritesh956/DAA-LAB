#include<stdio.h>
#include<stdlib.h>
int c=0;

int maxele(int * a,int low,int high){
if(low>=high){
    if(a[high]%2==0){
        return 1;
    }
    return 0;
}
int mid=(low+high)/2;
int left=maxele(a,low,mid);
int right=maxele(a,mid+1,high);

return left+right;

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
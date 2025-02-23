#include<stdio.h>
#include<stdlib.h>
int result=1;
int expo(int a,int b){

    if(b==0){
        return 1;
    }
    result=expo(a,b/2);
    result*=result;
    if(b%2!=0){
        result*= a;
    }
    return result;

}

void main(){
    printf("%d\n", expo(2,2));
}
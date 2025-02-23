#include <stdio.h>

int graph[10][10];
int q[100];
int indegree[100]={0};
int front=0;
int rear=0;
int n;int k=0;
int poporder[100];
void topological(int n ){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1){
                indegree[j]++;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q[rear++]=i;
        }
    }



    while(front<rear){
    int vertex=q[front++];
    poporder[k++]=vertex;
    for(int i=0;i<n;i++){
        if(graph[vertex][i]==1){
            indegree[i]--;
            if(indegree[i]==0){
                q[rear++]=i;
            }


        }

    }
    if(k==n){
        printf("Topological sort :-");
        for(int i=0;i<n;i++){
            printf("%d \n",poporder[i]);
        }
    }

    }

}


int main() {

    int i,j;

while(i!=-1){

    printf("enter start vertex and end vertex  enter -1 to stop");
    scanf("%d %d",&i,&j);
    graph[i][j]=1;
}
    topological(5);


    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int pick[6];

void combi(int N, int *arr, int start,int count){
    if(count==6){
        for (int i = 0; i < 6; i++)
        {
            printf("%d ",pick[i]);
        }   
        printf("\n");     
        return;
    }
    for(int i=start;i<N-5+count;i++){
        pick[count] = arr[i];
        combi(N,arr,i+1,count+1);
    }
}

int main(){
    int N;
    int *arr;
    while (1)
    {
        scanf("%d",&N);
        if(N==0) break;
        arr = (int*)malloc(sizeof(int)*N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d",&arr[i]);
        }
        combi(N,arr,0,0);
    }
}
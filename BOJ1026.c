#include <stdio.h>
#include <stdlib.h>


int main(){
    int N,tempnum;

    scanf("%d",&N);
    int *arrA = (int*)malloc(sizeof(int)*N);
    int *arrB = (int*)malloc(sizeof(int)*N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d",&arrA[i]);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d",&arrB[i]);
    }

    for (int i=N-1;i>0;i--){      //버블정렬    //인덱싱 재정렬
        for (int j=0;j<i;j++){
            if(arrB[j]>arrB[j+1]){
                tempnum = arrB[j+1];
                arrB[j+1] = arrB[j];
                arrB[j] = tempnum;
            }
        }
    }

    for (int i=0;i<N;i++){      //
        for (int j=N-1;j>i;j--){
            if(arrA[j]>arrA[j-1]){
                tempnum = arrA[j-1];
                arrA[j-1] = arrA[j];
                arrA[j] = tempnum;
            }
        }
    }
    int sum=0;
    for (int i = 0; i < N; i++){
        sum += arrA[i]*arrB[i];
    }

    printf("%d",sum);


}
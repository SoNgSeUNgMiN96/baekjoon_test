#include <stdio.h>
#include <stdlib.h>


int main(){
    long N;
    int *testsite = (int*)malloc(sizeof(int)*N);
    long sum = 0;
    long B,C;
    double temp;
    int temp2;

    scanf("%ld",&N);
    for (int i=0;i<N;i++){
        scanf("%d",&testsite[i]);
    }
    scanf("%ld %ld",&B,&C);

    for (int i=0;i<N;i++){
        testsite[i] -= B;
        sum++;
        if (testsite[i]>0){
            temp = testsite[i]/(double)C;
            temp2 = temp;
            if (temp2<temp){
                temp++;
            }
            sum+= temp;
        }
    }
    free(testsite);
    printf("%ld",sum);
    
    return 0;
}
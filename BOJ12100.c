#include<stdio.h>
#include<stdlib.h>

void left(int **arr , int N){
    for (int i=0;i<(N*N);i++){
        if ((i%N)!=0){
            for (int j=i;arr[0][j-1]==0;j--)
            {
                if ((j%N)==0){
                    break;
                }
                arr[0][j-1] = arr[0][j];
                arr[0][j] = 0; 
            }
        }
    }
    for (int i=0;i<(N*N);i++){
        if ((i%N)!=0){
            if (arr[0][i]==arr[0][i-1]){
                arr[0][i-1] += arr[0][i];
                arr[0][i]=0;
            }
        }
    }
    for (int i=0;i<(N*N);i++){
        if ((i%N)!=0){
            for (int j=i;arr[0][j-1]==0;j--)
            {
                if ((j%N)==0){
                    break;
                }
                arr[0][j-1] = arr[0][j];
                arr[0][j] = 0;
            }
            
        }
    }
}

void right(int **arr , int N){
    for (int i=(N*N-1);i>=0;i--){
        if ((i%N)!=(N-1)){
            for (int j=i;arr[0][j+1]==0;j++)
            {
                if ((j%N)==(N-1)){
                    break;
                }
                arr[0][j+1] = arr[0][j];
                arr[0][j] = 0; 
            }
        }
    }
    for (int i=(N*N-1);i>=0;i--){
        if ((i%N)!=(N-1)){
            if (arr[0][i]==arr[0][i+1]){
                arr[0][i+1] += arr[0][i];
                arr[0][i]=0;
            }
        }
    }
    for (int i=(N*N-1);i>=0;i--){
        if ((i%N)!=(N-1)){
            for (int j=i;arr[0][j+1]==0;j++)
            {
                if ((j%N)==(N-1)){
                    break;
                }
                arr[0][j+1] = arr[0][j];
                arr[0][j] = 0; 
            }
        }
    }
}

void down(int **arr , int N){
    for (int i=(N*N)-N-1;i>=0;i--){
        for (int j=i;arr[0][j+N]==0;j=j+N){
            if(j>=(N*(N-1))){
                break;
            }
            arr[0][j+N] = arr[0][j];
            arr[0][j] = 0; 
        }
    }

    for (int i=(N*N)-N-1;i>=0;i--){
        if (arr[0][i]==arr[0][i+N]){
            arr[0][i+N] += arr[0][i];
            arr[0][i]=0;
        }
    }
    for (int i=(N*N)-N-1;i>=0;i--){
        for (int j=i;arr[0][j+N]==0;j=j+N){
            if(j>=(N*(N-1))){
                break;
            }
            arr[0][j+N] = arr[0][j];
            arr[0][j] = 0; 
        }
    }
}

void up(int **arr , int N){
    for (int i=N;i<(N*N);i++){
        for (int j=i;arr[0][j-N]==0;j=j-N){
            if (j<N){
                break;
            }
            arr[0][j-N] = arr[0][j];
            arr[0][j]=0;
        }
    }
    for (int i=N;i<(N*N);i++){
        if (arr[0][i]==arr[0][i-N]){
            arr[0][i-N] += arr[0][i];
            arr[0][i]=0;
        }
    }
    for (int i=N;i<(N*N);i++){
        for (int j=i;arr[0][j-N]==0;j=j-N){
            if (j<N){
                break;
            }
            arr[0][j-N] = arr[0][j];
            arr[0][j]=0;
        }
    }
}

// direction 1 = left , 2 = right , 3 = up , 4 = down
int maxnum(int *Arr , int N , int direction, int count){
    
    //할당
    int *arr = (int*)malloc(sizeof(int)*N*N);
    int max =0,temp;
    
    //동기화
    for (int i=0;i<(N*N);i++){
        arr[i] = Arr[i];
    }
  
        
    if (count ==0){
        for (int i=1;i<5;i++){
            temp = maxnum(arr,N,i,(count+1));
            if (max<temp){
                max = temp;
            }
        }
    }
    else if(count<=5){
        switch (direction)
        {
            case 1:
                left(&arr,N);
            break;

            case 2:
                right(&arr,N);
            break;

            case 3:
                up(&arr,N);
            break;

            case 4:
                down(&arr,N);
            break;

        default:
            break;
        }
        for (int i=1;i<5;i++){
            temp = maxnum(arr,N,i,(count+1));
            if (max<temp){
                max = temp;
            }
        }
    }
    else{
        for (int i=0;i<(N*N);i++){
                if (max<arr[i]){
                    max = arr[i];
                }
            }
    }        
    free(arr);
    return max;
}


int main(){
    int N;
    int *arr;
    scanf("%d",&N);
    //할당
    arr = (int*)malloc(sizeof(int)*N*N);
    //입력받기
    for (int i=0;i<(N*N);i++){
        scanf("%d",&arr[i]);
    }

    printf("%d",maxnum(arr,N,0,0));
    free(arr);
    return 0;
}
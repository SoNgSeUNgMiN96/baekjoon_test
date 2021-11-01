#include<stdio.h>
#include<stdlib.h>

//처음에는 출력을 문자열로만 생각하다가 해결이 안되는것을 확인
void printstar(int start){
    
    --start;
    for (int i=0;i<start;i++){
        printf(" ");
    }
    printf("*\n");
    --start;
    for (int i=0;i<start;i++){
        printf(" ");
    }
    printf("* *\n");
    --start;
    for (int i=0;i<start;i++){
        printf(" ");
    }
    printf("*****\n");

}

void changestarori(int **arr ,int start,int line , int N){
    if (arr[line][start] == ' ')
        arr[line][start] = '*';
    else 
        arr[line][start] = ' ';
    if (arr[line+1][start-1] == ' ')
        arr[line+1][start-1] = '*';
    else
        arr[line+1][start-1] = ' ';
    if (arr[line+1][start+1] == ' ')
        arr[line+1][start+1] = '*';
    else
        arr[line+1][start+1] = ' ';
    for (int i=start-2;i<start+3;i++){
        if (arr[line+2][i] ==' ')
            arr[line+2][i] = '*';
        else
            arr[line+2][i] = ' ';
    }
    if (start + 4>=(2*N) || start-3<2|| line+4>N){
        return ;
    }
    else {
        changestarori(arr, start-3,line+3,N);
        changestarori(arr, start+3,line+3,N);
    }

}

void changestar(int **arr ,int start,int line , int N){
    if (N==3){
        arr[line][start] = '*';
        arr[line+1][start-1] = '*';
        arr[line+1][start+1] = '*';
        for (int i=start-2;i<start+3;i++)
            arr[line+2][i] = '*';
    }
    else {
        changestar(arr,start,line,N/2);
        changestar(arr,start - (N/2) ,line+(N/2),N/2);
        changestar(arr,start + (N/2) ,line+(N/2),N/2);
    }
}


int main(){
    char temp;
    int N;
    scanf("%d",&N);
    int **arr;
    arr = (int**)malloc(sizeof(int*)*N);
    for (int i=0;i<N;i++){
        arr[i] = (int*)malloc(sizeof(int)*N*2-1); 
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<(N*2-1);j++){
            arr[i][j] = ' ';
        }
    }


    //changestarori(arr,N-1,0,N);
    
    changestar(arr,N-1,0,N);


    for (int i=0;i<N;i++){
        for (int j=0;j<(N*2-1);j++){
            temp = arr[i][j];
            printf("%c",temp);
        }
        printf("\n");
    }
    

}
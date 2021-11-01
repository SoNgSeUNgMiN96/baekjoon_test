#include<stdio.h>
#include<stdlib.h>

//point[0] = x , point[1] = y , point[2] = d1 , point[3] = d2
void setzone(int ***arr, int point[], int N){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if ( ( i < (point[0]+point[2]) ) && ( j <= point[1] ) && ( i+j < point[0]+point[1] ) ){
                arr[0][i][j] = 1;
            }
            else if((i<=(point[0]+point[3]))&&(point[1]<j) && (j-i>point[1]-point[0]) ){
                arr[0][i][j] = 2;
            }
            else if( ( (point[0]+point[2]) <=i) && ( j< (point[1]-point[2]+point[3]) ) && ( j-i < point[1]-point[0]-(2*point[2]) )){
                arr[0][i][j] = 3;
            }else if( ( (point[0]+point[3]) <i) && ( (point[1]-point[2]+point[3]) <=j) && ( i+j > point[0]+point[1]+(2*point[3]) ) ) {
                arr[0][i][j] = 4;
            }else{
                arr[0][i][j] = 5;
            }
        }
    }
}

int allDcase(int **arr,int **zone,int x, int y, int N){  //해당 x ,y 에 대한 최대 최소 인구값의 차 계산

    int point[4], population[5]={0}; // 12345 영역의 인구를 저장 
    int min, max;  //최소인구와 최대인구를 저장
    int count=0;
    int sub,temp;

    for (int i=1; i<(N-1); i++){
        for (int j=1; j<(N-y); j++){
            if ( (y-i>=0) && (y+j<N) && (x+i+j<N) ){
                point[0] = x;
                point[1] = y;
                point[2] = i;
                point[3] = j;
                setzone(&zone,point,N);
                for(int k=0;k<N;k++){
                    for (int u=0;u<N;u++){
                        if (zone[k][u]==1){
                            population[0] +=arr[k][u];
                        }
                        else if (zone[k][u]==2){
                            population[1] +=arr[k][u];
                        }
                        else if (zone[k][u]==3){
                            population[2] +=arr[k][u];
                        }
                        else if (zone[k][u]==4){
                            population[3] +=arr[k][u];
                        }
                        else{
                            population[4] +=arr[k][u];
                        }
                    }
                }

                for(int k=0;k<5;k++){
                    if (k==0){
                        min = population[k];
                        max = population[k];
                    }
                    if (min>population[k]){
                        min =population[k];
                    }
                    if (max<population[k]){
                        max = population[k];
                    }
                }
                for(int k=0;k<5;k++){
                    population[k] = 0;
                }
                
                temp  = max - min;
                if (count==0){
                    sub =temp;
                    count++;
                }
                else if (sub>temp){
                    sub = temp;
                }
            }
        }
    }
    return sub;
}

int calculateall(int **arr, int **zone , int N){
    int sub;   //최소인구와 최대인구를 저장
    int temp;

    for (int i=0; i<(N-2); i++){
        for (int j=1; j<(N-1); j++){
            temp = allDcase(arr,zone,i,j,N);
            if (i==0 && j==1){
                sub = temp;
            }
            else if(sub>temp){
                sub = temp;
            }
        }
    }
    return sub;
}


int main(){
    int N;
    
    scanf("%d",&N);
    int **arr, **zone;

    arr = (int**)malloc(sizeof(int*)*N);
    for (int i=0;i<N;i++){
        arr[i] = (int*)malloc(sizeof(int)*N);
    }

    zone = (int**)malloc(sizeof(int*)*N);
    for (int i=0;i<N;i++){
        zone[i] = (int*)malloc(sizeof(int)*N);
    }


    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    printf("%d",calculateall(arr,zone,N));

    for (int i=0;i<N;i++){
        free(arr[i]);
    }
    free(arr);
    for (int i=0;i<N;i++){
        free(zone[i]);
    }
    free(zone);
}
#include<stdio.h>
#include<stdlib.h>

void spread(int **arr,int A, int B){
    int count;
    while (1)
    {
        count=0;
        for(int i=0;i<(A*B);i++){
            if(arr[0][i]==2){
                if (i==0){//왼쪽 위 모서리일때
                    //오른쪽 확인
                    if(arr[0][i+1]==0){ 
                        arr[0][i+1]=3;
                        count++;
                    }//아래 확인
                    if(arr[0][i+B]==0){
                        arr[0][i+B]=3;
                        count++;
                    }
                }
                else if(i==(B-1)){ //오른쪽 위 모서리일때
                    //왼쪽 확인
                    if(arr[0][i-1]==0){
                        arr[0][i-1]=3;
                        count++;
                    }//아래 확인
                    if(arr[0][i+B]==0){
                        arr[0][i+B]=3;
                        count++;
                    }
                }
                else if(i==(A*B-B)){//왼쪽 아래 모서리일때
                    //오른쪽 확인
                    if(arr[0][i+1]==0){ 
                        arr[0][i+1]=3;
                        count++;
                    }//위 확인
                    if(arr[0][i-B]==0){
                        arr[0][i-B]=3;
                        count++;
                    }
                }
                else if(i==(A*B-1)){//오른쪽 아래 모서리일때
                    //왼쪽 확인
                    if(arr[0][i-1]==0){
                        arr[0][i-1]=3;
                        count++;
                    }//위 확인
                    if(arr[0][i-B]==0){
                        arr[0][i-B]=3;
                        count++;
                    }
                }
                else if(i<B){//윗모서리
                    //왼쪽 확인
                    if(arr[0][i-1]==0){
                        arr[0][i-1]=3;
                        count++;
                    }//오른쪽 확인
                    if(arr[0][i+1]==0){ 
                        arr[0][i+1]=3;
                        count++;
                    }//아래 확인
                    if(arr[0][i+B]==0){
                        arr[0][i+B]=3;
                        count++;
                    }
                }
                else if(i%B==0){//왼쪽 모서리
                    //오른쪽 확인
                    if(arr[0][i+1]==0){ 
                        arr[0][i+1]=3;
                        count++;
                    }//아래 확인
                    if(arr[0][i+B]==0){
                        arr[0][i+B]=3;
                        count++;
                    }//위 확인
                    if(arr[0][i-B]==0){
                        arr[0][i-B]=3;
                        count++;
                    }
                }
                else if(i%B==(B-1)){//오른쪽 모서리
                    //왼쪽 확인
                    if(arr[0][i-1]==0){
                        arr[0][i-1]=3;
                        count++;
                    }//아래 확인
                    if(arr[0][i+B]==0){
                        arr[0][i+B]=3;
                        count++;
                    }//위 확인
                    if(arr[0][i-B]==0){
                        arr[0][i-B]=3;
                        count++;
                    }
                }else if(i>=(A*B-B)){//아래 모서리
                    //왼쪽 확인
                    if(arr[0][i-1]==0){
                        arr[0][i-1]=3;
                        count++;
                    }//오른쪽 확인
                    if(arr[0][i+1]==0){ 
                        arr[0][i+1]=3;
                        count++;
                    }//위 확인
                    if(arr[0][i-B]==0){
                        arr[0][i-B]=3;
                        count++;
                    }
                }else{ //중앙
                    //왼쪽 확인
                    if(arr[0][i-1]==0){
                        arr[0][i-1]=3;
                        count++;
                    }//오른쪽 확인
                    if(arr[0][i+1]==0){ 
                        arr[0][i+1]=3;
                        count++;
                    }//아래 확인
                    if(arr[0][i+B]==0){
                        arr[0][i+B]=3;
                        count++;
                    }//위 확인
                    if(arr[0][i-B]==0){
                        arr[0][i-B]=3;
                        count++;
                    }
                }
            }
        }
        if(count==0){
            break;
        }
        else {
            for(int i=0;i<(A*B);i++){
                if (arr[0][i]==3){
                    arr[0][i]=2;
                }
            }
        }

    }           
}
        
int countzero(int *arr,int A, int B){

    int count=0;
    for(int i=0;i<(A*B);i++){
        if(arr[i]==0){
            count++;
        }   
    }
    return count;
}

int setwall(int *Arr,int A, int B){
    int wallcheck=countzero(Arr,A,B);//벽이 들어올 수 있는 총 칸수(0의 갯수)
    int *arr = (int*)malloc(sizeof(int)*A*B);
    int *wall = (int*)malloc(sizeof(int)*wallcheck); //0의 갯수 대로 배열생성
    int max=0,temp;


    //복사
    for(int i=0;i<(A*B);i++){
        arr[i] =Arr[i];
    }

    for (int j=0;j<wallcheck;){
        for(int i=0;i<(A*B);i++){
            if(Arr[i]==0){
                wall[j]=i;
                j++;
            }
        }
    }
    
    for (int i=0;i<(wallcheck-2);i++){
        for(int j=(i+1);j<(wallcheck-1);j++){
            for(int k=(j+1);k<wallcheck;k++){
                arr[wall[i]]=1;
                arr[wall[j]]=1;
                arr[wall[k]]=1;
                spread(&arr,A,B);
                temp = countzero(arr,A,B);
                if (max<temp){
                    max =temp;
                }
                for(int r=0;r<(A*B);r++){
                    arr[r] =Arr[r];
                }
            }
        }
    }

    free(arr);
    return max;
}

int main(){
    int A,B;
    int *arr;
    scanf("%d %d",&A,&B);
    //할당
    arr = (int*)malloc(sizeof(int)*A*B);
    //입력받기
    for (int i=0;i<(A*B);i++){
        scanf("%d",&arr[i]);
    }
    
    printf("%d",setwall(arr,A,B));


    free(arr);
    return 0;
}
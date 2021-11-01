#include <stdio.h>
#include <stdlib.h>


//쓰레기를 넣다가 , 차의 수용량이 모자란경우 돌아옴 , 또는 딱 맞게 넣은경우도 일단 돌아옴, 그리고 더이상 쓰레기가 없는경우도 돌아옴,

int main(){
    int test_case;
    int *answer;
    int capacity , N , capacitytemp , distancesum;
    int **branchinformation;
    int trashsum;

    scanf("%d",&test_case);
    answer = (int*)malloc(sizeof(int)*test_case);

    for (int i=0;i<test_case;i++){
        scanf("%d %d", &capacity , &N);
        capacitytemp = capacity;    //동기화
        branchinformation = (int**)malloc(sizeof(int*)*N);
        trashsum =0;


        for (int j=0; j<N;j++){ //쓰레기들의 값을 읽어들여 동기화   //0번인덱스가 거리 1번인덱스가 쓰레기양
            branchinformation[j] = (int*)malloc(sizeof(int)*2);
            scanf("%d %d",&branchinformation[j][0] , &branchinformation[j][1]);
            trashsum += branchinformation[j][1];

        }



        int j;
        distancesum = 0;
        
        for (j=0;j<N;j++){
        
            if (capacitytemp > branchinformation[j][1]){  //쓰레기 수용이 가능하다면
                capacitytemp -= branchinformation[j][1];
                trashsum -= branchinformation[j][1]; //총량을 죽여줌
                branchinformation[j][1] = 0;
                    
                if (trashsum==0){
                    distancesum += branchinformation[j][0]*2; //현재위치부터 되돌아간다.
                    break;
                }
            }else if(capacitytemp == branchinformation[j][1]){
                distancesum += branchinformation[j][0]*2; //현재위치부터 되돌아간다.
                trashsum  -= branchinformation[j][1];
                branchinformation[j][1] = 0;
                if(trashsum==0){
                    break;
                }
                capacitytemp = capacity;    //수용량 다시 복구
                j=-1;   //0부터 다시 시작.
                continue ;
                
            }else{
                distancesum += branchinformation[j][0]*2; //현재위치부터 되돌아간다.
                capacitytemp = capacity;    //수용량 다시 복구
                j=-1;   //0부터 다시 시작.
                continue ;

            }

        }

        answer[i] = distancesum ;

    }

    for (int i=0; i<test_case;i++){

        printf("%d\n",answer[i]);
    }


}
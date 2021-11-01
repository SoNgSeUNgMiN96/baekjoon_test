#include<stdio.h>
#include<stdlib.h>


struct queue{       //여기서 데이터 타입만 수정하면 됨
    int x;
    int time;
    struct queue *next;
}typedef queue;

typedef struct {
    queue *front;
}front;

typedef struct {
    queue *rear;
}rear;

front *Q;
rear *R;

front *createqueue(){   //큐를 만들면 큐의 프론트가 초기값0xFFFFFFF 을 가지게 하고 큐가 비었는지를 검사하는 값으로 쓰임
    front *Q;
    Q = (front *)malloc(sizeof(front));
    Q->front = (queue *)malloc(sizeof(queue));
    Q->front->x = 0xFFFFFFF;
    Q->front->time = 0;
    return Q;
}
rear *enqueuefirst(front *Q,int X, int Time){   //이 시점에 rear 가 생성되고 rear 를 반납함 
    rear *R;
    queue *temp =(queue *)malloc(sizeof(queue)); 
    temp->time = Time;
    temp->x = X;
    temp->next= NULL;
    Q->front->next =temp;
    R = (rear *)malloc(sizeof(rear));
    R->rear  = Q->front->next;    //첫 큐는 프론트의 넥스트를 레어가 가르킴
    return R;
}

void enqueue(rear *R, int X, int Time){     // rear와 X(좌표) 와  Time(시간)을 받아 새로운 노드를 생성하고 레어 뒤를 이어줌
    queue *temp;
    temp = (queue *)malloc(sizeof(queue));
    temp->x = X;
    temp->time = Time;
    temp->next = NULL;
    R->rear->next =temp;
    R ->rear = temp;
}


queue *dequeue(front *F){   //temp 에 front 를 가르키게 한 후 front 를 한칸 미룬다 . 그리고 방금 temp를 반납한다  -> 메인함수에서받은 템프를 free해주어야함
    queue *temp;
    if(F->front->next == NULL){
        return NULL;
    }
    temp = F->front->next;
    if (F->front->next->next!=NULL){
        F->front->next = F->front->next->next;
    }
    else if (F->front->next->next==NULL){ 
        F->front->next = NULL;
        R->rear = F->front;
    }
    return temp;
}




int M;
int virus[10]={0,};
int viruscount=0;
int N , min =2500;
int vipick[10] = {0, };



int spread(int **arr){ //바이러스가 모두 퍼진 시간을 돌려준다.
    
    Q = createqueue();
    queue *temp;
    int time ;

    int zero=0 ;
    for(int i=0;i<(N*N);i++){
        if (arr[0][i]==0){
            zero++;
        }
    }

    int *aarr = (int*)malloc(sizeof(int)*N*N);      //바이러스 퍼트리기 전 복사를 한다.
    for(int i=0;i<(N*N);i++){
        aarr[i]=arr[0][i];
    }


    R = enqueuefirst(Q,virus[vipick[0]],0);     //처음 뽑힌것을 첫 큐에 넣고 바이러스로 변경
    aarr[virus[vipick[0]]] =2;

    for (int i=1;i<M;i++ ){
        enqueue(R,virus[vipick[i]] ,0);
        aarr[virus[vipick[i]]] =2;
    }   //큐에 넣어줌 (최초로 뽑은 애들)

    if (zero==0){
        return 0;
    }

  
    while (1)
    {
        temp= dequeue(Q);
        if (temp==NULL){
            break;
        }
        if (temp->x%N!=0){//왼쪽확인 가능하다면
            //왼쪽확인
            if(aarr[temp->x-1]==0){
                aarr[temp->x-1]=2;
                --zero;
                if(zero==0){
                    time = temp->time;
                    free(temp);
                    free(aarr);
                    return time+1;
                }
                enqueue(R,temp->x-1,temp->time+1);
            }
            else if(aarr[temp->x-1]==4){
                aarr[temp->x-1]=2;
                enqueue(R,temp->x-1,temp->time+1);
            }
        }
        //오른쪽 확인 가능하다면
        if (temp->x%N!=(N-1)){
            if(aarr[temp->x+1]==0){ 
                aarr[temp->x+1]=2;
                --zero;
                if(zero==0){
                    time = temp->time;
                    free(temp);
                    free(aarr);
                    return time+1;
                }
                enqueue(R,temp->x+1,temp->time+1);
            }
            else if(aarr[temp->x+1]==4){ 
                aarr[temp->x+1]=2;
                enqueue(R,temp->x+1,temp->time+1);
            }
        }
                //아래 확인이 가능하다면
         if (temp->x<(N*N-N)){
            //아래 확인
            if(aarr[temp->x+N]==0){
                aarr[temp->x+N]=2;
                --zero;
                if(zero==0){
                    time = temp->time;
                    free(temp);
                    free(aarr);
                    return time+1;
                }
                enqueue(R,temp->x+N,temp->time+1);
            }
            else if(aarr[temp->x+N]==4){
                aarr[temp->x+N]=2;
                enqueue(R,temp->x+N,temp->time+1);
            }
        }
        //위 확인가능하다면
            if(temp->x>=N){
                //위 확인
                if(aarr[temp->x-N]==0){
                    aarr[temp->x-N]=2;
                    --zero;
                    if(zero==0){
                        time = temp->time;
                        free(temp);
                        free(aarr);
                        return time+1;
                    }
                    enqueue(R,temp->x-N,temp->time+1);
                }
                else if(aarr[temp->x-N]==4){
                    aarr[temp->x-N]=2;
                    enqueue(R,temp->x-N,temp->time+1);
                }
            }
            free(temp);  
    }
    free(aarr);  
    return -1;        
}
        


void combi(int start , int m,int **arr){
    int temp;
    if (m<M){
        for (int i=start; i<viruscount;i++){
            vipick[m] = i;
            combi(i+1,m+1,arr);
        }
    }
    else{
        temp =spread(arr);
        if (min>temp&&temp!=-1){
                min = temp;
        }
    }
}



int main(){
    
    int *arr;
    scanf("%d %d",&N,&M);
    //할당

    arr = (int*)malloc(sizeof(int)*N*N);
    //입력받기
    for (int i=0;i<(N*N);i++){
        scanf("%d",&arr[i]);
        if (arr[i]==2){
            virus[viruscount]=i;
            viruscount++;
        }
    }
    for (int j=0;j<viruscount;j++){  //바이러스를 기록하고 초기화한다.(4로)
        arr[virus[j]]=4;
    }
    combi(0,0,&arr);
    if (min==2500){
        min = -1;
    }
    printf("%d",min);


    free(arr);
    return 0;
}
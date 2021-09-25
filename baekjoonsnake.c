#include<stdio.h>
#include<stdlib.h>

int N,K,L;
int *distance;
char *direction;
int time =0;
int code =0;

struct point{
    int x;
    int y;
}typedef point;

struct direc{
    int code;
    struct direc *L;
    struct direc *D;
}typedef direc;


struct queue{       //여기서 데이터 타입만 수정하면 됨
    int x;
    int y;
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

void createqueue(){   //큐를 만들면 큐의 프론트가 초기값0xFFFFFFF 을 가지게 하고 큐가 비었는지를 검사하는 값으로 쓰임
    Q = (front *)malloc(sizeof(front));
    Q->front = (queue *)malloc(sizeof(queue));
    Q->front->x = 0xFFFFFFF;
    Q->front->y = 0xFFFFFFF;
}
void enqueuefirst(int X, int Y){   //이 시점에 rear 가 생성되고 rear 를 반납함 
    queue *temp =(queue *)malloc(sizeof(queue)); 
    temp->y = Y;
    temp->x = X;
    temp->next= NULL;
    Q->front->next =temp;
    R = (rear *)malloc(sizeof(rear));
    R->rear  = Q->front->next;    //첫 큐는 프론트의 넥스트를 레어가 가르킴
}

void enqueue(int X, int Y){     // rear와 X(좌표) 와  Time(시간)을 받아 새로운 노드를 생성하고 레어 뒤를 이어줌
    queue *temp;
    temp = (queue *)malloc(sizeof(queue));
    temp->x = X;
    temp->y = Y;
    temp->next = NULL;
    R->rear->next =temp;
    R ->rear = temp;
}


queue *dequeue(){   //temp 에 front 를 가르키게 한 후 front 를 한칸 미룬다 . 그리고 방금 temp를 반납한다  -> 메인함수에서받은 템프를 free해주어야함
    queue *temp;
    if(Q->front->next == NULL){
        return NULL;
    }
    temp = Q->front->next;
    if (Q->front->next->next!=NULL){
        Q->front->next = Q->front->next->next;
    }
    else if (Q->front->next->next==NULL){ 
        Q->front->next = NULL;
        R->rear = Q->front;
    }
    return temp;
}





point **apple;
int **map;
point snake={0,0};
direc *right;
direc *down;
direc *left;
direc *up;
direc *cursor;

// return 값이 0이면 게임 오버 , 1이면 계속을 나타낸다  //L은 왼쪽 D는 오른쪽으로 꺽는다 
int move(int dis , char LD){
    queue *temp;

    switch (cursor->code)
    {
    case 1:
        for(int i=0;i<dis;i++){
            time++;
            if(snake.y+1<N){
                snake.y +=1;
                //일반적으로 비어있는곳으로 이동할경우
                if (map[snake.x][snake.y]==0){
                    
                    map[snake.x][snake.y]=1;
                    enqueue(snake.x,snake.y);
                    temp = dequeue();
                    map[temp->x][temp->y]=0;
                    free(temp);
                }else if (map[snake.x][snake.y]==1){
                    return 0;
                }else{  //사과를 먹을경우
                    map[snake.x][snake.y]=1;
                    enqueue(snake.x,snake.y);
                }

            }else{  //벽을 만날경우
                return 0;
            }
        }
        if (LD=='L'){
            cursor = cursor->L;
        }
        else{
            cursor = cursor->D;
        }
        break;
    case 2://down일때
        for(int i=0;i<dis;i++){
            time++;
            if(snake.x+1<N){
                snake.x +=1;
                if (map[snake.x][snake.y]==0){
                    map[snake.x][snake.y]=1;
                    enqueue(snake.x,snake.y);
                    temp = dequeue();
                    map[temp->x][temp->y]=0;
                    free(temp);
                }else if (map[snake.x][snake.y]==1){
                    return 0;
                }else{  //사과를 먹을경우
                    map[snake.x][snake.y]=1;
                    enqueue(snake.x,snake.y);
                }

            }else{
                return 0;
            }
        }
        if (LD=='L'){
            cursor = cursor->L;
        }
        else{
            cursor = cursor->D;
        }
        break;
    case 3://left일때
        for(int i=0;i<dis;i++){
            time++;
            if(snake.y-1>=0){
                snake.y -=1;
                if (map[snake.x][snake.y]==0){
                    map[snake.x][snake.y]=1;
                    enqueue(snake.x,snake.y);
                    temp = dequeue();
                    map[temp->x][temp->y]=0;
                    free(temp);
                }else if (map[snake.x][snake.y]==1){
                    return 0;
                }else{  //사과를 먹을경우
                    map[snake.x][snake.y]=1;
                    enqueue(snake.x,snake.y);
                }
            }else{
                return 0;
            }
        }
        if (LD=='L'){
            cursor = cursor->L;
        }
        else{
            cursor = cursor->D;
            
        }
        break;
    case 4://up일때
        for(int i=0;i<dis;i++){
            time++;
            if(snake.x-1>=0){
                snake.x -=1;
                if (map[snake.x][snake.y]==0){
                    map[snake.x][snake.y]=1;
                    enqueue(snake.x,snake.y);
                    temp = dequeue();
                    map[temp->x][temp->y]=0;
                    free(temp);
                }else if (map[snake.x][snake.y]==1){
                    return 0;
                }else{  //사과를 먹을경우
                    map[snake.x][snake.y]=1;
                    enqueue(snake.x,snake.y);
                }
            }else{
                return 0;
            }
        }
        if (LD=='L'){
            cursor = cursor->L;
        }
        else{
            cursor = cursor->D;
        }
        break;
    default:
        break;
    }
    return 1;
}

int main(){
    int x,y;
    createqueue();
    right = (direc*)malloc(sizeof(direc));
    down = (direc*)malloc(sizeof(direc));
    left = (direc*)malloc(sizeof(direc));
    up = (direc*)malloc(sizeof(direc));
    right->L =up;
    right->D =down;
    right->code =1;
    down->L = right;
    down->D=left;
    down->code =2;
    left->L=down;
    left->D=up;
    left->code=3;
    up->D=right;
    up->L=left;
    up->code=4;
    cursor = right;


    scanf("%d %d",&N,&K);

    
    map = (int**)malloc(sizeof(int*)*N);
    for (int i=0;i<N;i++){
        map[i] = (int*)malloc(sizeof(int)*N);
        for(int j=0;j<N;j++){
            map[i][j]=0;
        }
    }
    //애플의 좌표를 받을 동적구조체를 할당한다.
    apple = (point**)malloc(sizeof(point)*K);

    //입력받기 사과를 그림 
    for (int i=0;i<K;i++){
        scanf("%d",&x);
        scanf("%d",&y);
        map[x-1][y-1] = 2;
    }

    enqueuefirst(0,0);
    map[snake.x][snake.y]=1;

    //방향전환 횟수를 입력받는다.
    scanf("%d",&L);
    
    distance = (int*)malloc(sizeof(int)*L);
    direction = (char*)malloc(sizeof(char)*L);
    for (int i = 0; i <L; i++)
    {
        scanf("%d %c",&distance[i], &direction[i]);
    }
    

    for (int i=0;i<L;i++){
        distance[i] -=time;
        if (move(distance[i],direction[i])==0){
            printf("%d",time);
            
            for (int i=0;i<K;i++){
                free(apple[i]);
            }
            free(apple);
            free(direction);
            free(distance);
            return 0;
        }
    }
    //마지막 이동만이 남았다 100칸을 이동하여 , 무조건 게임오버시킨다.
    move(100,'D');


    //현재 맵 출력
    printf("%d",time);

    
    for (int i=0;i<K;i++){
        free(apple[i]);
    }
    free(apple);
    free(direction);
    free(distance);
    return 0;
}
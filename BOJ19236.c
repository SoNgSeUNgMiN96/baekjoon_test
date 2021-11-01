#include<stdio.h>
#include<stdlib.h>


// 1 = ↑, 2 =  ↖, 3 = ←, 4 = ↙, 5 = ↓,6 = ↘, 7 = →, 8 = ↗ 
void move(int Map[][4][4][2] , int i,int j){
    Map[0][i][j][1] = Map[0][i][j][1]%8;
    int temp[2];
    switch (Map[0][i][j][1])
    {
    case 1:
        if (i!=0){  //빈 인덱스의 값에 접근할까봐 이프 내 이프문
            if (Map[0][i-1][j][0]!=0){  //0을 샤크로 넣어놓았음  이동 가능하면 이동
                temp [0] = Map[0][i-1][j][0];
                temp [1] = Map[0][i-1][j][1];
                Map[0][i-1][j][1] = Map[0][i][j][1];
                Map[0][i-1][j][0] = Map[0][i][j][0];
                Map[0][i][j][1] = temp[1];
                Map[0][i][j][0] = temp[0];
            }
            else{
                Map[0][i][j][1]++;
                move(Map,i,j);
            }
        }else{
            Map[0][i][j][1]++;
            move(Map,i,j);
        }
        break;
    case 2:
        if (i!=0&&j!=0){
            if (Map[0][i-1][j-1][0]!=0){
                temp [0] = Map[0][i-1][j-1][0];
                temp [1] = Map[0][i-1][j-1][1];
                Map[0][i-1][j-1][1] = Map[0][i][j][1];
                Map[0][i-1][j-1][0] = Map[0][i][j][0];
                Map[0][i][j][1] = temp[1];
                Map[0][i][j][0] = temp[0];
            }
            else{
                Map[0][i][j][1]++;
                move(Map,i,j);
            }
        }else{
            Map[0][i][j][1]++;
            move(Map,i,j);
        }
        break;
    case 3:
        if (j!=0){
            if (Map[0][i][j-1][0]!=0){
                temp [0] = Map[0][i][j-1][0];
                temp [1] = Map[0][i][j-1][1];
                Map[0][i][j-1][1] = Map[0][i][j][1];
                Map[0][i][j-1][0] = Map[0][i][j][0];
                Map[0][i][j][1] = temp[1];
                Map[0][i][j][0] = temp[0];
            }else{
                Map[0][i][j][1]++;
                move(Map,i,j);
            }
        }else{
            Map[0][i][j][1]++;
            move(Map,i,j);
        }
        break;
    case 4:
        if (j!=0&&i!=3){
            if (Map[0][i+1][j-1][0]!=0){
                temp [0] = Map[0][i+1][j-1][0];
                temp [1] = Map[0][i+1][j-1][1];
                Map[0][i+1][j-1][1] = Map[0][i][j][1];
                Map[0][i+1][j-1][0] = Map[0][i][j][0];
                Map[0][i][j][1] = temp[1];
                Map[0][i][j][0] = temp[0];
            }
            else{
                Map[0][i][j][1]++;
                move(Map,i,j);
            }
        }else{
            Map[0][i][j][1]++;
            move(Map,i,j);
        }
        break;
    case 5:
         if (i!=3){
            if (Map[0][i+1][j][0]!=0){
                temp [0] = Map[0][i+1][j][0];
                temp [1] = Map[0][i+1][j][1];
                Map[0][i+1][j][1] = Map[0][i][j][1];
                Map[0][i+1][j][0] = Map[0][i][j][0];
                Map[0][i][j][1] = temp[1];
                Map[0][i][j][0] = temp[0];
            }
            else{
                Map[0][i][j][1]++;
                move(Map,i,j);
            }
        }else{
            Map[0][i][j][1]++;
            move(Map,i,j);
        }
        break;
    case 6:
        if (i!=3&&j!=3){
            if (Map[0][i+1][j+1][0]!=0){
                temp [0] = Map[0][i+1][j+1][0];
                temp [1] = Map[0][i+1][j+1][1];
                Map[0][i+1][j+1][1] = Map[0][i][j][1];
                Map[0][i+1][j+1][0] = Map[0][i][j][0];
                Map[0][i][j][1] = temp[1];
                Map[0][i][j][0] = temp[0];
            }
            else{
                Map[0][i][j][1]++;
                move(Map,i,j);
            }
        }else{
            Map[0][i][j][1]++;
            move(Map,i,j);
        }
        break;
    case 7:
        if (j!=3){
            if (Map[0][i][j+1][0]!=0){
                temp [0] = Map[0][i][j+1][0];
                temp [1] = Map[0][i][j+1][1];
                Map[0][i][j+1][1] = Map[0][i][j][1];
                Map[0][i][j+1][0] = Map[0][i][j][0];
                Map[0][i][j][1] = temp[1];
                Map[0][i][j][0] = temp[0];
            }
            else{
                Map[0][i][j][1]++;
                move(Map,i,j);
            }
        }else{
            Map[0][i][j][1]++;
            move(Map,i,j);
        }
        break;
    case 0:
        if (j!=3&&i!=0){
            if (Map[0][i-1][j+1][0]!=0){
                temp [0] = Map[0][i-1][j+1][0];
                temp [1] = Map[0][i-1][j+1][1];
                Map[0][i-1][j+1][1] = Map[0][i][j][1];
                Map[0][i-1][j+1][0] = Map[0][i][j][0];
                Map[0][i][j][1] = temp[1];
                Map[0][i][j][0] = temp[0];
            }
            else{
                Map[0][i][j][1]++;
                move(Map,i,j);
            }
        }else{
            Map[0][i][j][1]++;
            move(Map,i,j);
        }
        break;
    default:
        break;
    }
}


void printfish(int Map[4][4][2]){
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            printf("fish num=%d direction = %d\t",Map[i][j][0],Map[i][j][1]);
        }
        printf("\n");
    }
    printf("\n");
}
//상어는 기존 땅을 -1로 만들고 물고기를 먹고 나면 0으로 만든다.
// 1 = ↑, 2 =  ↖, 3 = ←, 4 = ↙, 5 = ↓,6 = ↘, 7 = →, 8 = ↗ 

int simulation(int Map[][4][4][2], int sharki,int sharkj,int distance){
    int maxsum=0,temp;
    int copyMap[4][4][2];       //복사할 맵 생성
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            copyMap[i][j][0] = Map[0][i][j][0];
            copyMap[i][j][1] = Map[0][i][j][1];
        }
    }
    if (distance==0){
        temp = simulation(&copyMap,sharki,sharkj,1);
        if (maxsum<temp){
            maxsum=temp;
        }
        temp = simulation(&copyMap,sharki,sharkj,2);
        if (maxsum<temp){
            maxsum=temp;
        }
        temp = simulation(&copyMap,sharki,sharkj,3);
        if (maxsum<temp){
            maxsum=temp;
        }
        return maxsum;
    }
    copyMap[sharki][sharkj][1] = copyMap[sharki][sharkj][1]%8;
    switch (copyMap[sharki][sharkj][1])
    {
    case 1:
        if (sharki-distance>=0){  //빈 인덱스의 값에 접근할까봐 이프 내 이프문
            if (copyMap[sharki-distance][sharkj][0]!=-1){  //빈땅이 아니라면 이동
                maxsum +=copyMap[sharki-distance][sharkj][0];
                copyMap[sharki][sharkj][0] = -1;    //기존 상어가 있던 땅을 빈땅으로 만듬
                copyMap[sharki-distance][sharkj][0] = 0;    //상어가 잡아 먹음
                fishmove(&copyMap);
                return maxsum + simulation(&copyMap,sharki-distance,sharkj,0);
            }
            else{
                return -1;
            }
        }else{
           return -1;
        }
        break;
    case 2:
        if (sharki-distance>=0&&sharkj-distance>=0){  //빈 인덱스의 값에 접근할까봐 이프 내 이프문
            if (copyMap[sharki-distance][sharkj-distance][0]!=-1){  //빈땅이 아니라면 이동
                maxsum +=copyMap[sharki-distance][sharkj-distance][0];
                copyMap[sharki][sharkj][0] = -1;    //기존 상어가 있던 땅을 빈땅으로 만듬
                copyMap[sharki-distance][sharkj-distance][0] = 0;    //상어가 잡아 먹음
                fishmove(&copyMap);
                return maxsum + simulation(&copyMap,sharki-distance,sharkj-distance,0);
            }
            else{
                return -1;
            }
        }else{
           return -1;
        }
        break;
    case 3:
        if (sharkj-distance>=0){  //빈 인덱스의 값에 접근할까봐 이프 내 이프문
            if (copyMap[sharki][sharkj-distance][0]!=-1){  //빈땅이 아니라면 이동
                maxsum +=copyMap[sharki][sharkj-distance][0];
                copyMap[sharki][sharkj][0] = -1;    //기존 상어가 있던 땅을 빈땅으로 만듬
                copyMap[sharki][sharkj-distance][0] = 0;    //상어가 잡아 먹음
                fishmove(&copyMap);
                return maxsum + simulation(&copyMap,sharki,sharkj-distance,0);
            }
            else{
                return -1;
            }
        }else{
           return -1;
        }
        break;
    case 4:
        if (sharki+distance<4&&sharkj-distance>=0){  //빈 인덱스의 값에 접근할까봐 이프 내 이프문
            if (copyMap[sharki+distance][sharkj-distance][0]!=-1){  //빈땅이 아니라면 이동
                maxsum +=copyMap[sharki+distance][sharkj-distance][0];
                copyMap[sharki][sharkj][0] = -1;    //기존 상어가 있던 땅을 빈땅으로 만듬
                copyMap[sharki+distance][sharkj-distance][0] = 0;    //상어가 잡아 먹음
                fishmove(&copyMap);
                return maxsum + simulation(&copyMap,sharki+distance,sharkj-distance,0);
            }
            else{
                return -1;
            }
        }else{
           return -1;
        }
        break;
    case 5:
        if (sharki+distance<4){  //빈 인덱스의 값에 접근할까봐 이프 내 이프문
            if (copyMap[sharki+distance][sharkj][0]!=-1){  //빈땅이 아니라면 이동
                maxsum +=copyMap[sharki+distance][sharkj][0];
                copyMap[sharki][sharkj][0] = -1;    //기존 상어가 있던 땅을 빈땅으로 만듬
                copyMap[sharki+distance][sharkj][0] = 0;    //상어가 잡아 먹음
                fishmove(&copyMap);
                return maxsum + simulation(&copyMap,sharki+distance,sharkj,0);
            }
            else{
                return -1;
            }
        }else{
           return -1;
        }
        break;
    case 6:
        if (sharki+distance<4&&sharkj+distance<4){  //빈 인덱스의 값에 접근할까봐 이프 내 이프문
            if (copyMap[sharki+distance][sharkj+distance][0]!=-1){  //빈땅이 아니라면 이동
                maxsum +=copyMap[sharki+distance][sharkj+distance][0];
                copyMap[sharki][sharkj][0] = -1;    //기존 상어가 있던 땅을 빈땅으로 만듬
                copyMap[sharki+distance][sharkj+distance][0] = 0;    //상어가 잡아 먹음
                fishmove(&copyMap);
                return maxsum + simulation(&copyMap,sharki+distance,sharkj+distance,0);
            }
            else{
                return -1;
            }
        }else{
           return -1;
        }
        break;
    case 7:
        if (sharkj+distance<4){  //빈 인덱스의 값에 접근할까봐 이프 내 이프문
            if (copyMap[sharki][sharkj+distance][0]!=-1){  //빈땅이 아니라면 이동
                maxsum +=copyMap[sharki][sharkj+distance][0];
                copyMap[sharki][sharkj][0] = -1;    //기존 상어가 있던 땅을 빈땅으로 만듬
                copyMap[sharki][sharkj+distance][0] = 0;    //상어가 잡아 먹음
                fishmove(&copyMap);
                return maxsum + simulation(&copyMap,sharki,sharkj+distance,0);
            }
            else{
                return -1;
            }
        }else{
           return -1;
        }
        break;
    case 0:
        if (sharkj+distance<4&&sharki-distance>=0){  //빈 인덱스의 값에 접근할까봐 이프 내 이프문
            if (copyMap[sharki-distance][sharkj+distance][0]!=-1){  //빈땅이 아니라면 이동
                maxsum +=copyMap[sharki-distance][sharkj+distance][0];
                copyMap[sharki][sharkj][0] = -1;    //기존 상어가 있던 땅을 빈땅으로 만듬
                copyMap[sharki-distance][sharkj+distance][0] = 0;    //상어가 잡아 먹음
                fishmove(&copyMap);

                return maxsum + simulation(&copyMap,sharki-distance,sharkj+distance,0);
            }
            else{
                return -1;
            }
        }else{
           return -1;
        }
        break;
    default:
        printf("Errorrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr\n\n");
        break;
    }
}

void fishmove(int Map[][4][4][2]){
    int count=1;
    int d;
    while(1){
        if (count==17){
            break;
        }
        d=1;
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                if (count==Map[0][i][j][0]){
                    move(Map,i,j);
                    count++;
                    d=0;
                }
            }
        }
        if (d==1)
            count++;
    }
}


int main(){

    int map[4][4][2];
    int sharksum=0;

    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            scanf("%d %d",&map[i][j][0],&map[i][j][1]);
        }
    }
    
    sharksum += map[0][0][0];
    map[0][0][0]=0;     // 초기상태 까지 샤크가 먹고 이동한 상태에서 시뮬레이션이 시작함
    fishmove(&map);
    sharksum +=simulation(&map,0,0,0);

    printf("%d",sharksum);

}
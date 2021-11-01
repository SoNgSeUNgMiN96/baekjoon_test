#include<stdio.h>
#include<stdlib.h>

int N,K,L;
int distance;
char direction;
int time =0;

struct point{
    int x;
    int y;
}typedef point;

struct direc{
    int code;
    struct direc *L;
    struct direc *D;
}typedef direc;


point **apple;
int **map;
point snake={0,0};
direc *right;
direc *down;
direc *left;
direc *up;
direc *cursor;

int move(int dis , char LD){
    
}

int main(){
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
    up->D=left;
    up->L=right;
    up->code=4;
    cursor = right;

    scanf("%d %d",&N,&K);

    
    map = (int**)malloc(sizeof(int*)*N);
    for (int i=0;i<N;i++){
        map = (int*)malloc(sizeof(int)*N);
        for(int j=0;j<N;j++){
            map[i][j]=0;
        }
    }
    //애플의 좌표를 받을 동적구조체를 할당한다.
    apple = (point**)malloc(sizeof(point)*K);

    //입력받기 사과의 좌표를 받음
    for (int i=0;i<K;i++){
        apple[i] = (point*)malloc(sizeof(point));
        scanf("%d",&apple[i]->x);
        scanf("%d",&apple[i]->y);
    }


     for (int i=0;i<K;i++){
        printf("%d",apple[i]->x);
        printf("%d",apple[i]->y);
    }

    //방향전환 횟수를 입력받는다.
    scanf("%d",&L);

    for (int i=0;i<L;i++){
        scanf("%d %c",&distance, &direction);
        move(distance,direction);
    }

    printf("%d",time);

    for (int i=0;i<K;i++){
        free(apple[i]);
    }
    free(apple);
    return 0;
}
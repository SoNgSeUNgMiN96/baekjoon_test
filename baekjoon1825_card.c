#include <stdio.h>
#include <stdlib.h>

struct node{       //여기서 데이터 타입만 수정하면 됨
    int data;
    struct node *next;
    struct node *prev;
}typedef node;

typedef struct {
    node *head;
}nodehead;

typedef struct {
    node *tail;
}nodetail;

// 현재 버전은 링크드0 리스트를 하나만 생성하는 버전임.

nodehead *listhead;
nodetail *listtail;

void firstnode(int data){       //첫번째 노드를 생성한다.
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next =NULL;
    temp->prev =NULL;
    listhead = (nodehead*)malloc(sizeof(nodehead));
    listtail = (nodetail*)malloc(sizeof(nodetail));
    listhead->head = temp;
    listtail->tail = temp;
}

void addnode(int data){     //맨 앞에 노드 추가
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->prev = NULL;
    temp->next =listhead->head;
    listhead->head->prev = temp;
    listhead->head =temp;
}

void Shuffle(){ //맨 뒷 카드를 맨 앞으로 가져오는 셔플함수.

    node *temp = listtail->tail;
    listtail->tail->prev->next = NULL;
    listtail->tail = listtail->tail->prev;
    temp->next = listhead->head;
    listhead->head->prev=temp;
    temp->prev =NULL;
    listhead->head = temp;
}



int main(){
    int N;
    node *cursor;
    scanf("%d",&N);
    firstnode(N);

    for (int i=N-1;i>0;i--){
        addnode(i);

        for (int j=0;j<i;j++){
            Shuffle();
        }
    }

    for (cursor = listhead->head ; cursor!=NULL;cursor=cursor->next)
        printf("%d ",cursor->data);

}
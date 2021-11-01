#include<stdio.h>
#include<stdlib.h>

int map[50][50];
int chickenpick[13]= {0,};
int counthouse=0 , countchicken=0;
int N,M;
int min = 0xFFFFFF;
int **house,**chicken;

int countdis(){
    int sum = 0;
    int temp,temp2;
    int d1,d2;
    
    for (int i=0;i<counthouse;i++){
        temp  = 0xFFFFFF;
        for (int j=0;j<M;j++){
            if (house[i][0]>chicken[chickenpick[j]][0]){
                d2 = house[i][0] - chicken[chickenpick[j]][0];
            }
            else{
                d2 =  chicken[chickenpick[j]][0] - house[i][0];
            }
            if (house[i][1]>chicken[chickenpick[j]][1]){
                d1 = house[i][1] - chicken[chickenpick[j]][1];
            }
            else {
                d1 =  chicken[chickenpick[j]][1] - house[i][1];
            }
            temp2 = d1+d2;
            if (temp>temp2){
                temp =temp2;
            }
        }
        sum +=temp;
    }
    return sum;
}

void combichicken(int mcount,int start){
  
    if (mcount<M){
        for (int i=start;i<countchicken-M+mcount+1;i++){
            chickenpick[mcount]= i;
            combichicken(mcount+1,i+1);
        }
    }
    else {
        int temp = countdis();
        if (min>temp){
            min = temp;
        } 
    }
}


int main(){
    scanf("%d %d", &N,&M);
    int temp;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            scanf("%d",&map[i][j]);
            if (map[i][j]==1){
                counthouse++;
            }
            else if(map[i][j]==2){
                countchicken++;
            }
        }
    }


    house = (int**)malloc(sizeof(int*)*counthouse);
    chicken = (int**)malloc(sizeof(int*)*countchicken);
    for(int i=0;i<counthouse;i++){
        house[i] =(int*)malloc(sizeof(int)*2);
    } 
    for(int i=0;i<countchicken;i++){
        chicken[i] =(int*)malloc(sizeof(int)*2);
    } 
    counthouse = 0;
    countchicken = 0;
    
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (map[i][j]==1){
                house[counthouse][0] = i;
                house[counthouse][1] = j;
                counthouse++;
            }
            else if(map[i][j]==2){
                chicken[countchicken][0] = i;
                chicken[countchicken][1] = j;
                countchicken++;
            }
        }
    }
      
    combichicken(0,0);
    printf("%d",min);
}
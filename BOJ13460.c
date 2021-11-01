#include<stdio.h>
#include<stdlib.h>
// continue = 1 , fail = 2 , success = 3
int leftcheck(char **arr, int Bpoint[],int Rpoint[]){
    int condition = 1;
    if(Bpoint[1]<Rpoint[1]){
        while (1)
        {
            if (arr[Bpoint[0]][Bpoint[1]-1]=='O'){
                return 2;
            }
            else if (arr[Bpoint[0]][Bpoint[1]-1]=='#'){
                break;
            }
            else if((Bpoint[0]==Rpoint[0])&&((Bpoint[1]-1)==Rpoint[1])){
                break;
            }
            else{
                Bpoint[1] = Bpoint[1]-1;
            }
        }
        while (1)
        {
            if (arr[Rpoint[0]][Rpoint[1]-1]=='O'){
                return 3;
            }
            else if (arr[Rpoint[0]][Rpoint[1]-1]=='#'||((Bpoint[0]==Rpoint[0])&&(Bpoint[1]==(Rpoint[1]-1)))){
                return 1;
            }
            else{
                Rpoint[1] = Rpoint[1]-1;
            }    
        }
    }
    else{
        while (1)
        {
            if (arr[Rpoint[0]][Rpoint[1]-1]=='O'){
                condition =3;
                Rpoint[1] = Rpoint[1]-1;
                break;
            }
            else if ((arr[Rpoint[0]][Rpoint[1]-1]=='#')||((Bpoint[0]==Rpoint[0])&&(Bpoint[1]==(Rpoint[1]-1)))){
                break;
            }
            else{
                Rpoint[1] = Rpoint[1]-1;
            } 
        }
        while (1)
        {
            if (arr[Bpoint[0]][Bpoint[1]-1]=='O'){
                return 2;
            }
            else if ((arr[Bpoint[0]][Bpoint[1]-1]=='#')||((Bpoint[0]==Rpoint[0])&&((Bpoint[1]-1)==Rpoint[1]))){
                return condition;
            }
            else{
                Bpoint[1] = Bpoint[1]-1;
            }
        } 
    }
}
int rightcheck(char **arr, int Bpoint[],int Rpoint[]){
    int condition = 1;
    if(Bpoint[1]>Rpoint[1]){
        while (1)
        {
            if (arr[Bpoint[0]][Bpoint[1]+1]=='O'){
                return 2;
            }
            else if (arr[Bpoint[0]][Bpoint[1]+1]=='#'||(Bpoint[0]==Rpoint[0]&&(Bpoint[1]+1)==Rpoint[1])){
                break;
            }
            else{
                Bpoint[1] = Bpoint[1]+1;
            }
        }
        while (1)
        {
            if (arr[Rpoint[0]][Rpoint[1]+1]=='O'){
                return 3;
            }
            else if (arr[Rpoint[0]][Rpoint[1]+1]=='#'||(Bpoint[0]==Rpoint[0]&&Bpoint[1]==(Rpoint[1]+1))){
                return 1;
            }
            else{
                Rpoint[1] = Rpoint[1]+1;
            }    
        }
    }
    else{
        while (1)
        {
            if (arr[Rpoint[0]][Rpoint[1]+1]=='O'){
                condition =3;
                Rpoint[1] = Rpoint[1]+1;
                break;
            }
            else if (arr[Rpoint[0]][Rpoint[1]+1]=='#'){
                break;
            }
            else if((Bpoint[0]==Rpoint[0]&&(Bpoint[1]==(Rpoint[1]+1)))){
                break;
            }
            else{
                Rpoint[1] = Rpoint[1]+1;
            } 
        }
        while (1)
        {
            if (arr[Bpoint[0]][Bpoint[1]+1]=='O'){
                return 2;
            }
            else if (arr[Bpoint[0]][Bpoint[1]+1]=='#'||(Bpoint[0]==Rpoint[0]&&(Bpoint[1]+1)==Rpoint[1])){
                return condition;
            }
            else{
                Bpoint[1] = Bpoint[1]+1;
            }
        } 
    }
}

int upcheck(char **arr, int Bpoint[],int Rpoint[]){
    int condition = 1;
    if(Bpoint[0]<Rpoint[0]){
        while (1)
        {
            if (arr[Bpoint[0]-1][Bpoint[1]]=='O'){
                return 2;
            }
            else if (arr[Bpoint[0]-1][Bpoint[1]]=='#'||((Bpoint[0]-1)==Rpoint[0]&&Bpoint[1]==Rpoint[1])){
                break;
            }
            else{
                Bpoint[0] = Bpoint[0]-1;
            }
        }
        while (1)
        {
            if (arr[Rpoint[0]-1][Rpoint[1]]=='O'){
                return 3;
            }
            else if (arr[Rpoint[0]-1][Rpoint[1]]=='#'||(Bpoint[0]==(Rpoint[0]-1)&&Bpoint[1]==Rpoint[1])){
                return 1;
            }
            else{
                Rpoint[0] = Rpoint[0]-1;
            }    
        }
    }
    else{
        while (1)
        {
            if (arr[Rpoint[0]-1][Rpoint[1]]=='O'){
                condition =3;
                Rpoint[0] = Rpoint[0]-1;
                break;
            }
            else if (arr[Rpoint[0]-1][Rpoint[1]]=='#'||(Bpoint[0]==(Rpoint[0]-1)&&Bpoint[1]==Rpoint[1])){
                break;
            }
            else{
                Rpoint[0] = Rpoint[0]-1;
            } 
        }
        while (1)
        {
            if (arr[Bpoint[0]-1][Bpoint[1]]=='O'){
                return 2;
            }
            else if (arr[Bpoint[0]-1][Bpoint[1]]=='#'||((Bpoint[0]-1)==Rpoint[0]&&Bpoint[1]==Rpoint[1])){
                return condition;
            }
            else{
                Bpoint[0] = Bpoint[0]-1;
            }
        } 
    }
}

int downcheck(char **arr, int Bpoint[],int Rpoint[]){
    int condition = 1;
    if(Bpoint[0]>Rpoint[0]){
        while (1)
        {
            if (arr[Bpoint[0]+1][Bpoint[1]]=='O'){
                return 2;
            }
            else if (arr[Bpoint[0]+1][Bpoint[1]]=='#'||((Bpoint[0]+1)==Rpoint[0]&&Bpoint[1]==Rpoint[1])){
                break;
            }
            else{
                Bpoint[0] = Bpoint[0]+1;
            }
        }
        while (1)
        {
            if (arr[Rpoint[0]+1][Rpoint[1]]=='O'){
                return 3;
            }
            else if (arr[Rpoint[0]+1][Rpoint[1]]=='#'||(Bpoint[0]==(Rpoint[0]+1)&&Bpoint[1]==Rpoint[1])){
                return 1;
            }
            else{
                Rpoint[0] = Rpoint[0]+1;
            }    
        }
    }
    else{
        while (1)
        {
            if (arr[Rpoint[0]+1][Rpoint[1]]=='O'){
                condition =3;
                Rpoint[0] = Rpoint[0]+1;
                break;
            }
            else if (arr[Rpoint[0]+1][Rpoint[1]]=='#'||(Bpoint[0]==(Rpoint[0]+1)&&Bpoint[1]==Rpoint[1])){
                break;
            }
            else{
                Rpoint[0] = Rpoint[0]+1;
            } 
        }
        while (1)
        {
            if (arr[Bpoint[0]+1][Bpoint[1]]=='O'){
                return 2;
            }
            else if (arr[Bpoint[0]+1][Bpoint[1]]=='#'||((Bpoint[0]+1)==Rpoint[0]&&Bpoint[1]==Rpoint[1])){
                return condition;
            }
            else{
                Bpoint[0] = Bpoint[0]+1;
            }
        } 
    }
}
//0 = start , 1= left , 2 = right ,3 = up , 4 =  down
int checkshort(char **arr,int Bpoint[] , int Rpoint[], int check,int direction){
    int rp[2], bp[2];
    int sroot=11,temp;
    rp[0] = Rpoint[0];
    rp[1] = Rpoint[1];
    bp[0] = Bpoint[0];
    bp[1] = Bpoint[1];
    
    if (check==0){
        temp = checkshort(arr,bp,rp,check+1,1);
        if (sroot>temp){
            sroot= temp;
        }
        temp = checkshort(arr,bp,rp,check+1,2);
        if (sroot>temp){
            sroot= temp;
        }
        temp = checkshort(arr,bp,rp,check+1,3);
        if (sroot>temp){
            sroot= temp;
        }
        temp = checkshort(arr,bp,rp,check+1,4);
        if (sroot>temp){
            sroot= temp;
        }
        if(sroot>10){
            return -1;
        }
        else{
            return sroot;
        }
    }
    else if(check>10){
        return 11;
    }
    else if (direction==1){
        temp = leftcheck(arr,bp,rp);
        
        if (temp==1){
            temp = checkshort(arr,bp,rp,check+1,3);
            if (sroot>temp){
                sroot= temp;
            }
            temp = checkshort(arr,bp,rp,check+1,4);
            if (sroot>temp){
                sroot= temp;
            }
            return sroot;
        }
        else if (temp ==2){
            return 11;
        }
        else if(temp ==3){
            return check;
        }
    }
    else if (direction==2){
        temp = rightcheck(arr,bp,rp);
        if (temp==1){
            temp = checkshort(arr,bp,rp,check+1,3);
            if (sroot>temp){
                sroot= temp;
            }
            temp = checkshort(arr,bp,rp,check+1,4);
            if (sroot>temp){
                sroot= temp;
            }
            return sroot;
        }
        else if (temp ==2){
            return 11;
        }
        else if(temp ==3){
            return check;
        }
        
    }
    else if (direction==3){
        temp = upcheck(arr,bp,rp);
        if (temp==1){
            temp = checkshort(arr,bp,rp,check+1,1);
            if (sroot>temp){
                sroot= temp;
            }
            temp = checkshort(arr,bp,rp,check+1,2);
            if (sroot>temp){
                sroot= temp;
            }
            return sroot;
        }
        else if (temp ==2){
            return 11;
        }
        else if(temp ==3){
            return check;
        }
    }
    else if (direction==4){
        temp =downcheck(arr,bp,rp);
        if(temp ==1){
            temp = checkshort(arr,bp,rp,check+1,1);
            if (sroot>temp){
                sroot= temp;
            }
            temp = checkshort(arr,bp,rp,check+1,2);
            if (sroot>temp){
                sroot= temp;
            }
            return sroot;
        }
        else if (temp ==2){
            return 11;
        }
        else if(temp ==3){
            return check;
        }
    }
    else{
        return 11;
    }
}


int main(){
    int A,B;
    int bpoint[2], rpoint[2];
    scanf("%d %d",&A,&B);
    char **arr;
    char *temp = (char*)malloc(sizeof(char)*(B+1));

    arr = (char**)malloc(sizeof(char*)*A);
    for (int i=0;i<A;i++){
        arr[i] = (char*)malloc(sizeof(char)*B);
    }

    for (int i=0;i<A;i++){
        scanf("%s",temp);
        for (int j = 0; j < B; j++)
        {
            arr[i][j] = temp[j];
        }
    }

    for (int i=0;i<A;i++){
        for (int j=0; j<B;j++){
            if(arr[i][j]=='B'){
                bpoint[0] = i;
                bpoint[1] = j;
            }
            if(arr[i][j]=='R'){
                rpoint[0] = i;
                rpoint[1] = j; 
            }
        }
    }
    printf("%d",checkshort(arr,bpoint,rpoint,0,0));

    for (int i=0; i<A;i++){
        free(arr[i]);
    }
    free(arr);
    free(temp);
}
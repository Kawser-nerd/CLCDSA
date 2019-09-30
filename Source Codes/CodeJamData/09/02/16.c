#include <stdio.h>

int N,r,c,i,j,k;
char x='a'-1;
int table[105][105];
int isPass[105][105];

void set(){
    int i,j;
    x='a'-1;
    for(i=0;i<105;i++){
        for(j=0;j<105;j++){
            table[i][j]=99999;    
            isPass[i][j]=0;
        }
    }
}

char travel(int dirR,int dirC){
    int a,b=0;
    int min;
    if(!isPass[dirR][dirC]){
        min=table[dirR][dirC];
        if(table[dirR-1][dirC]<min){
            min=table[dirR-1][dirC];
            b='N';
        }
        if(table[dirR][dirC-1]<min){
            min=table[dirR][dirC-1];
            b='W';
        }
        if(table[dirR][dirC+1]<min){
            min=table[dirR][dirC+1];
            b='E';
        }
        if(table[dirR+1][dirC]<min){
            min=table[dirR+1][dirC];
            b='S';
        }
        if(b=='N'){
            a=travel(dirR-1,dirC);
        }else if(b=='W'){
            a=travel(dirR,dirC-1);
        }else if(b=='E'){
            a=travel(dirR,dirC+1);
        }else if(b=='S'){
            a=travel(dirR+1,dirC);
        }else{
            a=++x;    
        }
    }else{
        a=isPass[dirR][dirC];
    }
    isPass[dirR][dirC]=a;
    return a;    
}

void printTable(int k){
    int i,j;
    printf("Case #%d: \n",k);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            printf("%c ",isPass[i][j]);    
        }    
        printf("\n");
    }    
}

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&N);
    for(k=1;k<=N;k++){
        set();
        scanf("%d%d",&r,&c);
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                scanf("%d",&table[i][j]);    
            }    
        }
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                travel(i,j);    
            }    
        }
        printTable(k);
    }
    scanf(" ");
    return 0;    
}

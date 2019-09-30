#include<stdio.h>
#include<string.h>
int main(void){
int A,B,C,D,E,N,M,x,y,i,j,cou=0,cou2,cou3,v[1000000],w[1000000],min_i,en=0;
    char S[100],W[100],s[10],X,Y;
    scanf("%c",&X);
    if(X=='A'){
        printf("1\n");
    }else if(X=='B'){
        printf("2\n");
    }else if(X=='C'){
        printf("3\n");
    }else if(X=='D'){
        printf("4\n");
    }else if(X=='E'){
        printf("5\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&X);
     ^
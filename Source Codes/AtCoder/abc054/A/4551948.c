#include<stdio.h>
#include<string.h>
int main(void){
int A,B,C,D,E,N,M,x,y,cou=0,cou2,v[1000000],w[1000000],min_i,en=0;
    char S[10],W[10],s[10],X,Y;
   scanf("%d %d",&A,&B);
   if(A==B){
       printf("Draw");
   }else if(A==1){
       if(B!=1){
           printf("Alice");
       }
   }else if(B==1){
       if(A!=1){
           printf("Bob");
       }
   }else if(A>B){
       printf("Alice");
   }else{
       printf("Bob");
   }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d",&A,&B);
    ^
#include<stdio.h>
#include<string.h>
int main(void){
int A,B,C,D,E,N,M,x,y,cou=0,cou2,v[1000000],w[1000000],min_i,en=0;
    char S[100],W[100],s[10],X,Y;
   scanf("%d",&A);
   if(A==100){
       printf("Perfect\n");
   }else if(A>=90){
       printf("Great\n");
   }else if(A>=60){
       printf("Good\n");
   }else{
       printf("Bad\n");
   }
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&A);
    ^
#include<stdio.h>
#include<string.h>
int main(void){
int A,B,C,D,E,N,M,x,y,cou=0,cou2,v[1000000],w[1000000],min_i,en=0;
    char S[100],W[100],s[10],X,Y;
   scanf("%d",&A);
   B=A%10;
   C=(A%100-B)/10;
   D=(A%1000-A%100)/100;
   E=A/1000;
   if((B==C)&&(B==D)&&(B==E)){
       printf("SAME\n");
   }else{
       printf("DIFFERENT\n");
   }
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&A);
    ^
#include<stdio.h>
#include<string.h>
int main(void){
int A,B,C,D,E,N,M,x,y,i,j,cou=0,cou2,cou3,v[1000000],w[1000000],min_i,en=0;
    char S[100],W[100],s[10],X,Y;
   for(i=0;i<3;i++){
       scanf("%d %d",&v[i],&w[i]);
    cou+=v[i]*w[i]/10;
   }
    printf("%d\n",cou);
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%d %d",&v[i],&w[i]);
        ^
#include<stdio.h>
#include<string.h>
int main(void){
int A,B,C,D,E,N,M,x,y,cou=0,cou2,v[1000000],w[1000000],min_i,en=0;
    char S[100],W[100],s[10],X,Y;
   scanf("%d %d %d %d",&A,&B,&C,&D);
   if((double)B/A>(double)D/C){
       printf("TAKAHASHI\n");
   }else if((double)B/A==(double)D/C){
       printf("DRAW\n");
   }else{
       printf("AOKI\n");
   }
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d %d %d",&A,&B,&C,&D);
    ^
#include<stdio.h>
#include<string.h>
int main(void){
int A,B,C,D,E,N,M,x,y,cou=0,cou2,cou3,v[1000000],w[1000000],min_i,en=0;
    char S[100],W[100],s[10],X,Y;
   scanf("%d %d %d",&A,&B,&C);
    if(A>B)
        cou++;

    if(C>B)
        cou++;

    if(A>C)
        cou2++;

    if(B>C)
        cou2++;

    if(B>A)
    cou3++;

    if(C>A)
    cou3++;

    printf("%d\n",cou3+1);
    printf("%d\n",cou+1);
    printf("%d\n",cou2+1);
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d %d",&A,&B,&C);
    ^
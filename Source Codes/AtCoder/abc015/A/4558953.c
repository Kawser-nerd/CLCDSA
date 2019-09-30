#include<stdio.h>
#include<string.h>
int main(void){
int A,B,C,D,E,N,M,x,y,i,j,cou=0,cou2,cou3,v[1000000],w[1000000],min_i,en=0;
    char S[100],W[100],s[10],X,Y;
   scanf("%s %s",&S,&W);
   A=strlen(S);
   B=strlen(W);
   if(A>B){
       printf("%s\n",S);
   }else{
       printf("%s\n",W);
   }
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
    scanf("%s %s",&S,&W);
          ^
./Main.c:6:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[100]’ [-Wformat=]
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s %s",&S,&W);
    ^
#include<stdio.h>
#include<string.h>
int main(void){
int A,B,C,D,E,N,M,x,y,cou=0,cou2,v[1000000],w[1000000],min_i,en=0;
    char S[20],W[10],s[10],X,Y;
   scanf("%s",&S);
   for(int i=0;i<5;i++){
       printf("%c",S[i]);
   }
   printf(" ");
   for(int i=6;i<13;i++){
       printf("%c",S[i]);
   }
   printf(" ");
   for(int i=14;i<19;i++){
       printf("%c",S[i]);
   }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[20]’ [-Wformat=]
    scanf("%s",&S);
          ^
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",&S);
    ^
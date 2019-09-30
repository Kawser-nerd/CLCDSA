#include<stdio.h>
#include<string.h>
int main(void){
int A,B,C,D,E,N,M,x,y,cou=0,cou2,v[1000000],w[1000000],min_i,en=0;
    char S[20],W[100],s[10],X,Y;
   scanf("%s %s %s",&S,&W,&s);
   printf("%c%c%c",S[0],W[0],s[0]);
   
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[20]’ [-Wformat=]
    scanf("%s %s %s",&S,&W,&s);
          ^
./Main.c:6:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[100]’ [-Wformat=]
./Main.c:6:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 4 has type ‘char (*)[10]’ [-Wformat=]
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s %s %s",&S,&W,&s);
    ^
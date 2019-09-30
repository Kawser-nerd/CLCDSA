#include<stdio.h>
#include<string.h>
int main(void){
int A,B,C,D,E,N,M,x,y,i,j,cou=0,cou2,cou3,v[1000000],w[1000000],min_i,en=0;
    char S[100],W[100],s[100],X,Y;
    scanf("%s %s %s",&S,&W,&s);
    if(S[i]>=97&&S[i]<=122){
      S[i]=S[i]-32;
  }
  if(W[i]>=97&&W[i]<=122){
      W[i]=W[i]-32;
  }
  if(s[i]>=97&&s[i]<=122){
      s[i]=s[i]-32;
  }
    printf("%c%c%c",S[0],W[0],s[0]);
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
     scanf("%s %s %s",&S,&W,&s);
           ^
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[100]’ [-Wformat=]
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 4 has type ‘char (*)[100]’ [-Wformat=]
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %s %s",&S,&W,&s);
     ^
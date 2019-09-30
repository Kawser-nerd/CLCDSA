#include<stdio.h>
char *P[]={"No","Yes"};
char f;

int n, m;
char s[11], c, i;
int main(){
  scanf("%s", s);
  while(c=s[i++]){
    n=n*10+c-'0';
    m=m+c-'0';
  }
  f = (n%m)==0;
  puts(P[f]);
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
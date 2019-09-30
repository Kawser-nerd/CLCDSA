#include <stdio.h>
#define DIV 1000000007
int main(){
  char S[200000];
  long long int a,b,c,n;
  int N;
  
  scanf("%s",S);
  while(S[++N]!='\0') ;

  a=1;b=c=n=0;  
  for(int i=0;i<N;i++)
    switch(S[i]){
    case 'A':
      b=(b+a)%DIV;
      break;
    case 'B':
      c=(c+b)%DIV;
      break;
    case 'C':
      n=(n+c)%DIV;
      break;
    case '?':
      n=(n*3+c)%DIV;
      c=(c*3+b)%DIV;
      b=(b*3+a)%DIV;
      a=a*3%DIV;
      break;
    }
        
  printf("%lld\n",n);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^
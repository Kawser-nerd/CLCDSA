#include <stdio.h>
#define DIV 1000000007
int main(){
  char S[200000];
  int N=0;
  int a[200000];
  int b[200000];
  int c[200000];
  int n;

  scanf("%s",S);
  while(S[++N]!='\0') ;
  
  n=1;
  for(int i=0;i<N-2;i++)
    if(S[i]=='A')
      a[i]=n;
    else if(S[i]=='?'){
      a[i]=n;
      n=(long long int)n*3%DIV;
    }else
      a[i]=0;

  n=a[0];
  for(int i=1;i<N-1;i++)
    if(S[i]=='B')
      b[i]=n;
    else if(S[i]=='?'){
      b[i]=n;
      n=((long long int)n*3+a[i])%DIV;
    } else if(S[i]=='A'){
      b[i]=0;
      n=((long long int)n+a[i])%DIV;
    }else
      b[i]=0;

  n=b[1];
  for(int i=2;i<N;i++)
    if(S[i]=='C')
      c[i]=n;
    else if(S[i]=='?'){
      c[i]=n;
      n=((long long int)n*3+b[i])%DIV;
    }else if(S[i]=='B'){
      c[i]=0;
      n=((long long int)n+b[i])%DIV;
    }else
      c[i]=0;

  n=c[2];
  for(int i=3;i<N;i++)
    if(S[i]=='?')
      n=((long long int)n*3+c[i])%DIV;
    else if(S[i]=='C')
      n=((long long int)n+c[i])%DIV;

  //  for(int i=0;i<N;i++)
  //    printf("%c %d %d %d\n",S[i],a[i],b[i],c[i]);
  
  printf("%d\n",n);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^
#include <stdio.h>

int main(){
  int N;
  char S[500000];
  int W[500000],E[500000],w=0,e=0;
  int min=500000;
  
  scanf("%d",&N);
  scanf("%s",S);

  for(int i=0;i<N;i++)
    if(S[i]=='W')
      W[i]=w++;
    else
      W[i]=w;

  for(int i=N-1;i>=0;i--)
    if(S[i]=='E')
      E[i]=e++;
    else
      E[i]=e;

  for(int i=0;i<N;i++)
    if(min>W[i]+E[i])
      min = W[i]+E[i];

  printf("%d\n",min);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^
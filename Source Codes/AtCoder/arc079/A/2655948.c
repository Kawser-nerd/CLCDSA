#include<stdio.h>

int main(){
  long n,m,a,b,i;
  int g[2][200001]={};
  scanf("%ld %ld",&n,&m);
  for(i=0;i<m;i++){
    scanf("%ld %ld",&a,&b);
    if(a==1)
      g[0][b]=1;
    else if(b==1)
      g[0][a]=1;
    else if(a==n)
      g[1][b]=1;
    else if(b==n)
      g[1][a]=1;
  }
  for(i=2;i<n;i++)
    if(g[0][i]==1&&g[1][i]==1){
      printf("POSSIBLE\n");
      return 0;
    }
  printf("IMPOSSIBLE\n");
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld",&n,&m);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld",&a,&b);
     ^
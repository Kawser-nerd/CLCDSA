#include <stdio.h>
#include <stdlib.h>
#define INF 1 << 30

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  int a[N],b[N];
  int c[M],d[M];
  for(int i = 0;i < N;i++) scanf("%d%d",&a[i],&b[i]);
  for(int i = 0;i < M;i++) scanf("%d%d",&c[i],&d[i]);

  for(int i = 0;i < N;i++){
    int dist = INF;
    int num = 1;
    for(int j = 0;j < M;j++){
      if(dist > abs(a[i]-c[j])+abs(b[i]-d[j])){
        dist = abs(a[i]-c[j])+abs(b[i]-d[j]);
        num = j+1;
      }
    }
    printf("%d\n",num);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:18:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d%d",&a[i],&b[i]);
                            ^
./Main.c:19:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < M;i++) scanf("%d%d",&c[i],&d[i]);
                            ^
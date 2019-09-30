#include <stdio.h>
#define INF 1 << 29

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int N;
  scanf("%d",&N);

  int b[N];
  int p[N],maxp[N],minp[N];
  for(int i = 1;i < N;i++) scanf("%d",&b[i]);
  for(int i = 0;i < N;i++){
    maxp[i] = 0;
    minp[i] = INF;
  }
  for(int i = N-1;i >= 0;i--){
    if(maxp[i] == 0) p[i] = 1;
    else p[i] = maxp[i]+minp[i]+1;

    if(i == 0) break;
    maxp[b[i]-1] = max(maxp[b[i]-1],p[i]);
    minp[b[i]-1] = min(minp[b[i]-1],p[i]);
  }

  printf("%d\n",p[0]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:24:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 1;i < N;i++) scanf("%d",&b[i]);
                            ^
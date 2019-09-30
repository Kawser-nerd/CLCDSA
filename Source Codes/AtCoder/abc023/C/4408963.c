#include <stdio.h>

int main(void){
  int R,C,K,N;
  scanf("%d%d%d%d",&R,&C,&K,&N);

  int r[N],c[N];
  int tate[C],yoko[R];
  int tatenum[K+1],yokonum[K+1];
  for(int i = 0;i < C;i++){
    tate[i] = 0;
  }
  for(int i = 0;i < R;i++){
    yoko[i] = 0;
  }
  for(int i = 0;i <= K;i++){
    tatenum[i] = yokonum[i] = 0;
  }
  for(int i = 0;i < N;i++){
    scanf("%d%d",&r[i],&c[i]);
    r[i]--; c[i]--;
    yoko[r[i]]++;
    tate[c[i]]++;
  }

  for(int i = 0;i < C;i++){
    if(tate[i] <= K) tatenum[tate[i]]++;
  }
  for(int i = 0;i < R;i++){
    if(yoko[i] <= K) yokonum[yoko[i]]++;
  }

  long long ans = 0;
  for(int i = 0;i <= K;i++){
    ans += tatenum[i]*yokonum[K-i];
  }
  for(int i = 0;i < N;i++){
    if(yoko[r[i]]+tate[c[i]] == K) ans--;
    if(yoko[r[i]]+tate[c[i]] == K+1) ans++;
  }

  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&R,&C,&K,&N);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&r[i],&c[i]);
     ^
#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *b,const void *a){
  return *(long*)a-*(long*)b;
}

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int N,M,P,Q,R;
  int ans = 0;
  scanf("%d%d%d%d%d",&N,&M,&P,&Q,&R);

  int x[R],y[R],z[R];
  for(int i = 0;i < R;i++){
    scanf("%d%d%d",&x[i],&y[i],&z[i]);
  }

  int flag[N];
  int cnt;
  for(int i = 0;i < 1<<N;i++){
    cnt = 0;
    for(int j = 0;j < N;j++){
      if((i >> j)&1){
        flag[j] = 1;
        cnt++;
      }else flag[j] = 0;
    }
    if(cnt <= P){
      int point[M];
      for(int j = 0;j < M;j++) point[j] = 0;
      for(int j = 0;j < R;j++){
        for(int k = 0;k < N;k++){
          if(flag[k] == 0) continue;
          if(x[j]-1 == k) point[y[j]-1] += z[j];
        }
      }
      qsort(point,M,sizeof(int),compare_int);
      int res = 0;
      for(int j = 0;j < Q;j++){
        res += point[j];
      }
      ans = max(ans,res);
    }
  }

  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d",&N,&M,&P,&Q,&R);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x[i],&y[i],&z[i]);
     ^
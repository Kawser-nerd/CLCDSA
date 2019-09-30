#include <stdio.h>

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int N;
  scanf("%d",&N);

  int a[N];
  for(int i = 0;i < N ;i++){
    scanf("%d",&a[i]);
  }

  int ans = -100000;
  int aoki,takahashi;
  int maximam,cur;
  for(int i = 0;i < N;i++){
    maximam = -10000000;
    cur = -100000000;
    for(int j = 0;j < N;j++){
      if(i == j) continue;
      int cnt = 0;
      aoki = 0; takahashi = 0;
      for(int k = min(i,j);k <= max(i,j);k++){
        if(cnt%2 == 0) takahashi += a[k];
        else aoki += a[k];
        cnt++;
      }
      if(maximam < aoki){
        maximam = aoki;
        cur = takahashi;
      }
    }
    ans = max(ans,cur);
  }

  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^
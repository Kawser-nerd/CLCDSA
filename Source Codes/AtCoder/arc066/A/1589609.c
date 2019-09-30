#include <stdio.h>
#define mod 1000000007
#define ll long long

int main(){

  int n, i;
  int cnt[100001] = {0};
  ll ans = 1;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }

  int flag = 1;

  if(n % 2 == 1){
    if(cnt[0] != 1) flag = 0;
    for(i = 2; i <= n; i++) if(i % 2 == 0 && cnt[i] != 2) flag = 0;
  }else{
    for(i = 1; i < n; i++) if(i % 2 == 1 && cnt[i] != 2) flag = 0;
  }

  if(flag){
    for(i = 0; i < n/2; i++) ans = (ans * 2) % mod;
    printf("%lld\n", ans);
    return 0;
  }else{
    printf("0\n");
    return 0;
  }
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^
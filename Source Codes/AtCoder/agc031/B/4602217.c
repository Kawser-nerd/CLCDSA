#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  int c[n+1];
  int i;
  for(i=1;i<=n;i++){
    scanf("%d",&c[i]);
  }
  int c_idx[200001];
  for(i=1;i<=200000;i++){
    c_idx[i]=-1;
  }
  long long int ans[n+1];
  ans[1] = 1;
  c_idx[c[1]] = 1;
  for(i=2;i<=n;i++){
    if(c_idx[c[i]] == i-1 || c_idx[c[i]] == -1){
      ans[i] = ans[i-1];
    }else{
      ans[i] = (ans[i-1] + ans[c_idx[c[i]]]) % 1000000007;
    }
    c_idx[c[i]] = i;
  }
  printf("%lld\n", ans[n]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c[i]);
     ^
#include <stdio.h>
long long a[100010]={0};
long long used[100010]={0};
int main(void)
{
  int n, i, ans = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%lld", &a[i]);
  }

  for(i = 1; i < n; i++){
    if(a[i] > a[i-1]){
      while(a[i] >= a[i-1] && i < n){
	used[i] = 1;
	used[i-1] = 1;
	i++;
      }
      ans++;
    }
    else if(a[i] < a[i-1]){
      while(a[i] <= a[i-1] && i < n){
	used[i] = 1;
	used[i-1] = 1;
	i++;
      }
      ans++;
    }
  }
  if(used[n-1] != 1) ans++;
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &a[i]);
     ^
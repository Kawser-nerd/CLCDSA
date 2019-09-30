# include <stdio.h>

int main(){
  int n, k;
  int ans = 0;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++){
    int pos_x;
    scanf("%d", &pos_x);
    ans += (pos_x*2 < k)*2*pos_x + (pos_x*2 >= k)*2*(k-pos_x);
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &k);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &pos_x);
     ^
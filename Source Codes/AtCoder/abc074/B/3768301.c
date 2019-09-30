#include <stdio.h>

int main(){
  int n, k;
  int x[110] = {};
  int dist = 0;

  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; i++){
    scanf("%d", &x[i]);
  }

  for(int i = 1; i <= n; i++){
    if(x[i] - 0 < k - x[i]){
      dist += 2*x[i];
    }else{
      dist += 2*(k - x[i]);
    }
  }

  printf("%d\n", dist);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &n, &k);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x[i]);
     ^
#include <stdio.h>
int main(){
  int n,m,c,count = 0;
  int b[21];
  scanf("%d %d %d",&n,&m,&c);
  for (int i = 0; i < m; i++) {
    scanf("%d",&b[i]);
  }

  for (int i = 0; i < n; i++) {
    int ans = c;
    for (int j = 0; j < m; j++) {
      int a;
      scanf("%d",&a);
      ans += a * b[j];
    }
    if (ans > 0) {
      count++;
    }
  }
  printf("%d\n",count);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&m,&c);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b[i]);
     ^
./Main.c:14:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a);
       ^
#include<stdio.h>
int main(void)
{
  int  i, j, b, ans, n;
  scanf("%d", &n);
  int a[n];
  for (i=0; i<n; ++i){
    scanf("%d", &a[i]);
  }
  for (i=0; i<n; ++i) {
    for (j=i+1; j<n; ++j){
      if (a[i] > a[j]){
        b = a[i];
        a[i] = a[j];
        a[j] = b;
      }
    }
  }
    ans=a[n-1]-a[0];
    printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^
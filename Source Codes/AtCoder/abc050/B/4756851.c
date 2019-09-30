#include <stdio.h>

int main()
{
  int n,m;
  long long int t[100], p[100], x[100];
  
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%lld", &t[i]);
  
  scanf("%d", &m);
  
  for(int i=0;i<m;i++)
    scanf("%lld %lld", &p[i], &x[i]);
  
  int sum;
  long long int tmp[100];
  for(int i=0;i<m;i++){
    sum = 0;
    for(int k=0;k<n;k++) tmp[k] = t[k];
    tmp[p[i]-1] = x[i];
    for(int j=0;j<n;j++)
      sum += tmp[j];
    printf("%d\n", sum);
  }
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:9:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i=0;i<n;i++) scanf("%lld", &t[i]);
                        ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &m);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld", &p[i], &x[i]);
     ^
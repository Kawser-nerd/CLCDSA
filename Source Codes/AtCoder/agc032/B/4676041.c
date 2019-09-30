#include <stdio.h>

int main(){
  int s[100];
  int a[5000];
  int b[5000];
  int n;
  scanf("%d\n",&n);
  printf("%d\n",n*(n-1)/2-n/2);
  int even = (n+1)%2;
  for(int i=1; i<=n;i++){
    for(int j=i+1;j<=n;j++){
      if(i+j==n+even) continue;
      printf("%d %d\n",i, j);
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d\n",&n);
   ^
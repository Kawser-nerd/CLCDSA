#include <stdio.h>

int main(){
  int n;
  double sum = 0.0;
  char a[40] = "JPY";
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
    double x;
    char u[100];
    scanf("%lf %s",&x,u);
    if (u[0] == a[0]) {
      sum += x;
    }else{
      sum += x * 380000.0;
    }
  }
  printf("%lf\n",sum);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf %s",&x,u);
     ^
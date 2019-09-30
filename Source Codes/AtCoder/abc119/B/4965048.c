#include <stdio.h>

int main(){
  double total = 0;
  int N, i;

  scanf("%d", &N);

  for(i = 0; i < N; i++){
    double x;
    scanf("%lf", &x);
    char u[3] = {};
    scanf("%s", &u);
    
    if(u[0] == 'J'){
      total += x;
    }
    if(u[0] == 'B'){
      total += x * 380000.0;
    }
  }

  printf("%lf\n", total);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[3]’ [-Wformat=]
     scanf("%s", &u);
           ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf", &x);
     ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", &u);
     ^
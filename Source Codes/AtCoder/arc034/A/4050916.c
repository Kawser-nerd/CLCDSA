#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N, i;
  double max = 0;

  scanf("%d", &N);

  double a[N], b[N], c[N], d[N], e[N], t[N];

  for(i = 0; i < N; i++){
    scanf("%lf%lf%lf%lf%lf", &a[i], &b[i], &c[i], &d[i], &e[i]);
    t[i] = a[i] + b[i] + c[i] + d[i] + (e[i] * 110 / 900);
    if(max < t[i]){
      max = t[i];
    }
  }

  printf("%.5f\n", max);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf%lf%lf%lf%lf", &a[i], &b[i], &c[i], &d[i], &e[i]);
     ^
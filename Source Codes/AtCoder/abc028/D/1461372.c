#include<stdio.h>

int main(){
  int n,k;
  scanf("%d%d",&n,&k);

double nd = n , kd = k;
  double p,p1,p2,p3;


  p1 = (kd-1.0)*(nd-kd)/(nd*nd*nd)*6.0;
  p2 = (nd-1.0)/(nd*nd*nd)*3.0;
  p3 = 1/(nd*nd*nd);

  //printf("p1=%f\np2=%f\nP3=%f\n",p1,p2,p3);

  p = p1 + p2 + p3;
  printf("%.20f\n",p);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
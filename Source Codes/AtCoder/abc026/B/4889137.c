#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void *a,const void *b){
  return *(double*)b - *(double*)a;
}

int main(void){
  int n,i;
  scanf("%d",&n);
  double r[n],ans=0.0;
  for(i=0;i<n;i++) scanf("%lf",&r[i]);
  qsort(r,n,sizeof(double),cmp);
  for(i=0;i<n;i++) ans+=r[i]*r[i]*pow(-1,i);
  ans*=M_PI;
  printf("%f\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:13:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%lf",&r[i]);
                    ^
#include<stdio.h>

#define ABS(x) (((x)<0)?(-(x)):(x))

int main(void){
  int n,a[100000];
  int i,j,k;
  int max,m;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",a+i);
  for(i=1,max=a[0];i<n;i++) if(max<a[i]) max=a[i];
  for(i=1,m=a[0];i<n;i++){
    if(a[i]==max) continue;
    if(m==max) m=a[i];
    if(ABS(max/2-m)>ABS(max/2-a[i])) m=a[i];
  }
  printf("%d %d\n",max,m);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
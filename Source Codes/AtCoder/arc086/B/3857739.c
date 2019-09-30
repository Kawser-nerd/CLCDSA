#include<stdio.h>

void run(void){
  int n;
  scanf("%d",&n);
  int a[51];
  int i;
  for(i=1;i<=n;i++) scanf("%d",a+i);
  int min=1,max=1;
  for(i=2;i<=n;i++){
    if(a[min]>a[i]) min=i;
    if(a[max]<a[i]) max=i;
  }
  printf("%d\n",2*n-1);
  if(a[min]>=0 || a[max]>=-a[min]){
    for(i=1;i<=n;i++) printf("%d %d\n",max,i);
    for(i=2;i<=n;i++) printf("%d %d\n",i-1,i);
  } else {
    for(i=1;i<=n;i++) printf("%d %d\n",min,i);
    for(i=n-1;i>=1;i--) printf("%d %d\n",i+1,i);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d",a+i);
                     ^
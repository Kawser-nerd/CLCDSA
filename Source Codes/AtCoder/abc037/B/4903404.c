#include<stdio.h>

int main(void){
  int n,q,i,j,l,r,t;
  scanf("%d %d",&n,&q);
  int a[n];
  for(i=0;i<n;i++) a[i]=0;
  for(i=0;i<q;i++){
    scanf("%d %d %d",&l,&r,&t);
    for(j=l-1;j<r;j++) a[j] = t;
  }
  for(i=0;i<n;i++)printf("%d\n",a[i]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&q);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&l,&r,&t);
     ^
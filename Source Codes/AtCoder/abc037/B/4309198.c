#include <stdio.h>
int main() {
  int n,l,r,t,q,a[111]={},i,j;
  scanf("%d%d",&n,&q);
  for(i=0;i<q;i++){
    scanf("%d%d%d",&l,&r,&t);
    for(j=l;j<=r;j++){
      a[j-1]=t;
    }
  }
  for(i=0;i<n;i++) printf("%d\n",a[i]);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&q);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&l,&r,&t);
     ^
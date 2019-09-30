#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  int l,h,n;
  int a[51];
  scanf("%d%d%d",&l,&h,&n);
  for(int i=0; i<n; i++) {
    scanf("%d",&a[i]);
  }
  for(int i=0; i<n; i++) {
    if(a[i]>h) printf("%d\n",-1);
    else if(a[i]<l) printf("%d\n",l-a[i]);
    else printf("%d\n",0);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&l,&h,&n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^
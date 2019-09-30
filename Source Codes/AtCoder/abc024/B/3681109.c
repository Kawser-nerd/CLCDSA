#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int n,t,ans=0;
  int a[100001] = {};
  scanf("%d%d",&n,&t);
  for(int i=0; i<n; i++) {
    scanf("%d",&a[i]);
  }
  for(int i=0; i<n; i++) {
    if(i!=n-1 && a[i]+t>a[i+1]) {
      ans+=a[i+1]-a[i];
    }else{
      ans+=t;
    }
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&t);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^
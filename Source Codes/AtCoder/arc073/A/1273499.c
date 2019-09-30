#include <stdio.h>
int main(){

  int n,t,a[200000],result=0,i;

  scanf("%d %d",&n,&t);

  for(i = 0; i < n; i++) scanf("%d",&a[i]);

  for(i = 0; i < n-1; i++){

    if(a[i+1]-a[i] < t) result += a[i+1]-a[i];
    else result	+= t;

  }

  result += t;
  printf("%d\n",result);

  return 0;

} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&t);
   ^
./Main.c:8:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i = 0; i < n; i++) scanf("%d",&a[i]);
                          ^
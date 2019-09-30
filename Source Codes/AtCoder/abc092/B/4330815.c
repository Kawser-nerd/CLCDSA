#include <stdio.h>
int main(void){
  int n,d,x,i,j;
  scanf("%d%d%d",&n,&d,&x);
  int a[100];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int sum=x;
  for(i=0;i<n;i++){
    for(j=0;j<d;j++){
      if(j*a[i]+1<=d) sum+=1;
    }
  }
  printf("%d",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&d,&x);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^
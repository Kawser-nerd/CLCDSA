#include<stdio.h>
int main(){
  int n,d[300010],a,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    if(i%2==0)d[(n+i+1-n%2)/2]=a;//,printf("%d\n",(n+i+1-n%2)/2);
    else      d[(n-i-1    )/2]=a;//,printf("%d\n",(n-i-1    )/2);
  }
  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",n%2?d[n-i-1]:d[i]);
  }
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
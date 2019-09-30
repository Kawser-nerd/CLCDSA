#include<stdio.h>
int main(){
  int n,i,a[200001];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=n-1;i>=0;i-=2){
    printf("%d ",a[i]);
  }
  i+=1+2*(n%2);
  for(;i<n;i+=2){
    printf("%d ",a[i]);
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^
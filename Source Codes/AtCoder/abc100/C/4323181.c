#include<stdio.h>
int div2(int n){
  if(n%2) return 0;
  else return div2(n/2)+1;
}
int main(){
  int n,i,sum=0,a;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    sum+=div2(a);
  }
  printf("%d",sum);
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
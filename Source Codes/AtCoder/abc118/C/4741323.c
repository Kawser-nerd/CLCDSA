#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int gcd(int a, int b){
  return b?gcd(b,a%b):a;
}
int main(){
  int n,m,a;
  scanf("%d%d",&n,&m);
  while(--n){
    scanf("%d",&a);
    m=gcd(m,a);
  }
  printf("%d\n",m);
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
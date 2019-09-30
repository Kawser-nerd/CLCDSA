#include<stdio.h>
#include<stdlib.h>
int gcd(int,int*,int);
int GCD(int,int);
int main(void) {
  int N,X,x[100000],ans,i;
  scanf("%d %d",&N,&X);
  for(i=0;i<N;i++)scanf("%d",&x[i]);
  ans=gcd(N,x,X);
  printf("%d\n",ans);
  return 0;
}
int gcd(int N,int *x,int X) {
  int i,gcd=(int)abs(x[0]-X);
  if(N!=1)for(i=1;i<N;i++)gcd=GCD(gcd,abs(x[i]-X));
  return gcd;
}
int GCD(int A,int B) {
  int gcd;
  if(A==0){
    gcd=B;
  } else {
    if(B==0){
      gcd=A;
    } else {
      if(A<B) {
        B = B%A;
      } else {
        A = A%B;
      }
      gcd=GCD(A,B);
    }
  }
  return gcd;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&X);
   ^
./Main.c:8:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<N;i++)scanf("%d",&x[i]);
                   ^
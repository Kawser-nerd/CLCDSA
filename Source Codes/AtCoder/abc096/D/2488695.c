#include<stdio.h>

/*
  https://oeis.org/A003631
  "Primes congruent to 2 or 3 modulo 5"

  http://mathworld.wolfram.com/Wall-Sun-SunPrime.html
  "Wall-Sun-SunPrime"

  ?????????
 */

 
int fibmod(int*a,int*b,int n,int p){
  int x,y,tx,ty,F0,F1,tF0,tF1;
  y=0;
  x=F0=F1=1;
  --n;
  while(n){
    if(n&1){
      tx = x;
      ty = y;
      x  = (F1*tx+F0*ty)%p;
      y  = (F0*tx+(F1-F0)*ty)%p;
    }
    n>>=1;

    tF1=F1%p;
    tF0=F0%p;
    F1 = tF1 * tF1 %p + tF0 * tF0  %p;
    F0 = tF1 * tF0 %p + tF0 * (tF1-tF0) %p;
  }

  *a=x;
  *b=y;
  return 0;
}


int main(){
  int i,j,a,b,N;

  scanf("%d",&N);
  for(i=3;N;i+=10){
    fibmod(&a,&b,i,i);
    if(a*b%i==i-1){
      printf("%d ",i);
      --N;
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:43:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
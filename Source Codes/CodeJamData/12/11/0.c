#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

double in[200000];
double mul[200000];

int main(){
  int i,j,k,l,m,n;
  int A, B;
  int size, count=0;
  double res, tmp;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&A,&B);
    rep(i,A) scanf("%lf",in+i);
    res = 1e100;

    mul[0] = 1;
    rep(i,A) mul[i+1] = mul[i] * in[i];

    if(res > 1+B+1) res = 1+B+1;
    rep(i,A+1){
      tmp = (2*i+B-A+1) * mul[A-i] + (2*i+B-A+1+B+1) * (1-mul[A-i]);
      if(res > tmp) res = tmp;
    }

    printf("Case #%d: %.10f\n",++count,res);
  }

  return 0;
}

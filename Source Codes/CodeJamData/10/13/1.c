#include <stdio.h>
#include <math.h>
double oe;
int low(int a) { return ceil(a/oe); }
int hi(int a) { return floor(a*oe); }
typedef long long ll;

int main() {
  int cases,caseno=1,a1,a2,b1,b2,i,l,h;
  ll ans;
  oe=(1+sqrt(5))/2;
  scanf("%d",&cases);
  while(cases--) {
    scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
    ans=0;
    for(i=a1;i<=a2;i++) {
      l=low(i);
      h=hi(i);
      if(l<b1) l=b1;
      if(h>b2) h=b2;
      if(l<=h) ans+=(b2-b1+1)-(h-l+1);
      else ans+=b2-b1+1;
    }
    printf("Case #%d: %I64d\n",caseno++,ans);
  }
  return 0;
}

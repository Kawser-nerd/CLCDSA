#include <stdio.h>

long double x,c,f,r,s,ff;
long long i,j,k,l,m,n,t,tt;

int main() {

scanf("%lld", &t);

for(tt=1;tt<=t;tt++) {

scanf("%Lf %Lf %Lf",&c,&ff,&x);

f = 2.0L;
r = 0.0L;
s = x / f + 1.0;

if(x<c) s = x/f;
else 
  while(1) {
    if(r + x/f < s) s = r + x/f; 
      else break;
    r += c/f;
    f += ff;
  }


printf("Case #%lld: %Lf\n",tt,s);
}

return 0;
}
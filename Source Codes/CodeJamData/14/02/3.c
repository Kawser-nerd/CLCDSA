#include <stdio.h>
#include <limits.h>

typedef long double ldouble;

ldouble c,x,f;

ldouble sim(int ct)
{
  int i;
  ldouble t = 0,ic;
  ic = 2;
  for( i = 0; i <= ct; i++ ) {
    if( i == ct ) {
      t += x/ic;
    } else {
      t += c/ic;
      ic += f;
    }
  }
  return t;
}

int main(void)
{
  int T,ttt;
  ldouble ct,t;
  scanf("%d",&T);
  for( ttt = 1; ttt <= T; ttt++ ) {
    printf("Case #%d: ",ttt);
    scanf("%Lf%Lf%Lf",&c,&f,&x);
    ldouble res = LLONG_MAX;
    int from,to;
    from = 1;
    to = 1000000;
    for(; to-from > 1; ) {
      int mid = (from+to)/2;
      if( sim(mid-1)-sim(mid)>1e-9 ) from = mid;
      else to = mid;
    }
    res = sim(from);
    if( res > sim(0) ) res = sim(0);
    printf("%.10Lf\n",res);
  }
  return 0;
}

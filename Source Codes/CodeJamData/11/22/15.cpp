#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((long long)1e15)
#define pb push_back

using namespace std;

long long res, A[1234567];
int e;

int main()
{
  int t, cnt, i, v, c;
  long long d, p, l, r, m, s;
  bool fl;
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  scanf("%d", &t);
  for (cnt=1; cnt<=t; cnt++)
  {
    cerr<<cnt<<endl;
    memset(A,0,sizeof(A));
    res=0ll, e=0;
    scanf("%d%I64d", &c, &d);
    d*=(2ll);
    for (i=0; i<c; i++)
    {
      scanf("%I64d%d", &p, &v);
      while (v>0)
      {
        A[e]=2*p;
        e++, v--;
      }
    }
    sort(A,A+e);
    l=-(1ll), r=inf;
    while (r-l>1ll)
    {
      m=(l+r)/(2ll);
      //cerr<<l<<" "<<r<<" "<<m<<endl;
      s=A[0]-m, fl=0;
      for (i=1; i<e; i++)
      {
        s=max(s+d,A[i]-m);
        if (s>A[i]+m)
        {
          fl=1;
          l=m;
          break;
        }
      }
      //cerr<<s<<endl;
      if (!fl)
        r=m;
    }
    res=r;
    if (res%(2ll)==0ll)
      printf("Case #%d: %I64d\n", cnt, res/(2ll));
    else
      printf("Case #%d: %I64d.5\n", cnt, res/(2ll));
  }
  return 0;
}

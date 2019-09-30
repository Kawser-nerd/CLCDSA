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
#define inf ((int)1e9)
#define pb push_back

using namespace std;

bool operator < (pair<long double, long double> i, pair<long double, long double> j)
{
  if (i.first<j.first)
    return 1;
  if (i.first>j.first)
    return 0;
  return i.second<j.second;
}

pair<long double, long double> A[2000];

int main()
{
  int t, cnt, i, n;
  long double s, r, tm, res, b, e;
  freopen("in", "r", stdin);
  freopen(".out", "w", stdout);
  scanf("%d", &t);
  for (cnt=1; cnt<=t; cnt++)
  {
    res=0.0;
    memset(A,0,sizeof(A));
    //scanf("%lf%lf%lf%lf%d", &A[0].second, &s, &r, &tm, &n);
    cin>>A[0].second>>s>>r>>tm>>n;
    //cerr<<A[0].second<<endl;
    for (i=1; i<=n; i++)
    {
      //scanf("%lf%lf%lf", &b, &e, &A[i].first);
      cin>>b>>e>>A[i].first;
      A[i].second=e-b, A[0].second-=A[i].second;
    }
    sort(A,A+(n+1));
    for (i=0; i<=n; i++)
    {
      if (tm>=A[i].second/(A[i].first+r))
      {
        tm-=A[i].second/(A[i].first+r), res+=A[i].second/(A[i].first+r); 
        continue;
      }
      res+=tm, A[i].second-=(A[i].first+r)*tm, tm=0.0;
      res+=A[i].second/(A[i].first+s);
    }
    printf("Case #%d: %.9lf\n", cnt, (double)res);
  }
  return 0;
}

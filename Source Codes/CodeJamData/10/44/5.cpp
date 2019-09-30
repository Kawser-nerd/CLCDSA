#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

#define CLEAR(t) memset((t),0,sizeof(t))
#define FOR(i,a,b) for(__typeof(a)i=(a);i<=(b);++i)
#define FORD(i,a,b) for(__typeof(a)i=(a);i>=(b);--i)
#define REP(i,n) for(__typeof(n)i=0;i<(n);++i)
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)


double ax,ay,bx,by,cx,cy;
double PI;

void swap(double &x, double &y) { double t=x; x=y; y=t; }

double dist(double x, double y) { return sqrt(x*x+y*y); }

double aaa()
{
  double u=atan2(cy-ay,cx-ax) - atan2(by-ay,bx-ax);
  if(u<0) u=-u;
  if(u>2.0*PI) u-=2.0*PI;
  if(u>PI) u=2.0*PI-u;
  double r=dist(cx-ax,cy-ay);
  return (u*r*r) - (r*r*sin(u)*cos(u));
}

double calc()
{
  double res=0;
  res+=aaa();
  swap(ax,bx); swap(ay,by);
  res+=aaa();
  swap(ax,bx); swap(ay,by);
  return res;
}

void _case(int casenum)
{
  int n,m; scanf("%d%d",&n,&m);
  scanf("%lf%lf%lf%lf",&ax,&ay,&bx,&by);
  printf("Case #%d:",casenum);
  REP(i,m)
  {
    scanf("%lf%lf",&cx,&cy);
    printf(" %.9lf",calc());
  }
  printf("\n");
}

int main()
{
  PI=acos(0)*2;
  int n;
  scanf("%d ",&n);
  FOR(i,1,n) _case(i);
  return 0;
}

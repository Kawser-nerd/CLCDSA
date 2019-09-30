#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

#define N 3000

double p[N][N];
double sp[N][N];

int main()
{
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);
  for(int n=0;n<N;n++) {
    sp[n][0] = p[n][0] = n ? p[n-1][0]/2 : 1;
    for(int k=1;k<=n;k++)
    {
      p[n][k]=(p[n-1][k]+p[n-1][k-1])/2;
      sp[n][k] = p[n][k] + sp[n][k-1];
    }
  }
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    int n,x,y,k;
    scanf("%d%d%d",&n,&x,&y);
    for(k=0;;k++) {
      if(n<=4*k+1) break;
      n-=4*k+1;
    }
    x=abs(x);
    double res;
    if(x+y<2*k) res=1; else
    if(x+y>2*k) res=0; else
    if(n==4*k+1) res=1; else
    if(n==4*k) res = x>0; else
    {
      res=0;
      for(int z=y+1;z<=2*k;z++)
      {
        int w = n-z;
        if(w>2*k) continue;
        if(w==2*k) res+=sp[n][z]; else
        if(z==2*k) res+=sp[n][w]; else
          res+=p[n][z];
      }
    }
    printf("%.10lf\n",res);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS

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

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    int n;
    LL m;
    scanf("%d%lld",&n,&m);
    if(m>bit64(n-2)) {
      puts("IMPOSSIBLE");
    } else {
      puts("POSSIBLE");
      char a[55][55]={0};
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) a[i][j]='0';
      for(int i=0;i<n;i++)
        for(int j=i+1;j<n-1;j++) a[i][j]='1';
      a[0][n-1]='1';
      m--;
      for(int i=1;i<n-1;i++)
        if(m & bit64(i-1)) a[i][n-1]='1';
      for(int i=0;i<n;i++) puts(a[i]);
    }
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}

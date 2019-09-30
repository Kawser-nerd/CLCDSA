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
		printf("Case #%d:",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    int n;
    scanf("%d",&n);
    int a[111];
    for(int i=0;i<n;i++)
      scanf("%d",a+i);
    while(true) {
      int mx=0,mxi=0;
      VI b;
      for(int i=0;i<n;i++) {
        if(mx<a[i]) {
          mx=a[i];
          mxi=i;
        }
        if(a[i]) b.pb(i);
      }
      if(b.sz==0) break;
      assert(b.sz>1);
      if(b.sz==2) {
        printf(" %c%c",char(b[0]+'A'),char(b[1]+'A'));
        a[b[0]]--;
        a[b[1]]--;
      } else {
        printf(" %c",char(mxi+'A'));
        a[mxi]--;
      }
    }
    printf("\n");
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}

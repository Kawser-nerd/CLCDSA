#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;
typedef unsigned __int64 ULL;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

clock_t start=clock();

int main()
{
	freopen("d2.in","r",stdin);
	freopen("d2.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int n,i,x;
		scanf("%d",&n);
		int ans=n;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(i==x) ans--;
		}
		printf("%d\n",ans);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}

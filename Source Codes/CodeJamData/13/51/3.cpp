#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

LL a[37],b;

double solve(LL lev)
{
	if (lev < 0) return 0;
	int m = 0;
	LL sum = 0;
	REP(i,37)
		if (a[i] <= lev)
		{
			++m;
			sum += lev-a[i];
			LL over = 0;
		}
	LL over = 0;
	if (sum > b || m==0) return 0;
	double res = 0;
	REPD(i,m)
	{
		if (over+sum > b) break;
		res = max(res,(36.0/(i+1)-1.0)*sum-over);
		sum -= lev-a[i];
		over += lev-a[i]+1;
	}
	return res;
}

int main(int argc, char **argv)
{
	string FN = "A-large";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		int n;
		cin >> b >> n;
		CLEAR(a);
		REP(i,n)
			cin >> a[i];
		sort(a,a+37);
		double res = 0;
		FOR(k,1,37)
		{
			LL left = a[k-1];
			LL right = 2111000111000LL;
			while (left != right)
			{
				LL mid = (left+right+1)/2;
				LL need = 0;
				REP(i,37)
					if (i < k)
						need += mid-a[i];
					else
						need += max(mid+1-a[i],0LL);
				if (need > b)
					right = mid-1;
				else
					left = mid;
			}
			res = max(res,solve(left));
		}
		/*double res = 0;
		REP(i,37)
		{
			res = max(res,solve(a[i]+1));
			res = max(res,solve(a[i]));
			res = max(res,solve(a[i]-1));
		}
		LL sum = 0;
		LL cur = 0;
		REP(i,37)
		{
			LL inc = a[i]-cur;
			if (inc*i+sum <= b)
			{
				sum += inc*i;
				cur = a[i];
			}
			else
			{
				res = max(res, solve((b-sum)/i));
				break;
			}
		}
		/*FOR(i,0,5000) 
			res = max(res,solve(i));*/
		printf("%.12lf\n", res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}
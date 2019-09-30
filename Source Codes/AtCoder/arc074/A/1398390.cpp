#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <sstream>

#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RFOR(i,a,b) for (long long i=(b)-1;i>=(a);i--)
#define REP(i,n) for (long long i=0;i<(n);i++)
#define RREP(i,n) for (long long i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define INF INT_MAX/3
#define llinf LLONG_MAX/3
#define LLINF LLONG_MAX/3
#define PB push_back
#define pb push_back
#define MP make_pair
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PLL pair<long long,long long>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VLL vector<long long>
#define VULL vector<unsigned long long>
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define eps 1e-14
#define FST first
#define SCD second

using namespace std;

const LL ANS_MAX = 1000000007;

LL calc(LL s0, LL s1, LL s2)
{
	return MAX(s0, MAX(s1, s2)) - MIN(s0, MIN(s1, s2));
}

// ARC074C
int main()
{
	LL ret;

	LL H;
	LL W;
	cin >> H >> W;

	if (H % 3 == 0 || W % 3 == 0) {
		ret = 0;
	}
	else {
		{
			LL h0 = ceil((double)H / 3);
			LL w0 = W;
			LL h1 = H - h0;
			LL w1 = W / 2;
			LL h2 = H - h0;
			LL w2 = W - w1;
			ret = calc(h0 * w0, h1*w1, h2* w2);
		}
		{
			LL h0 = floor((double)H / 3);
			LL w0 = W;
			LL h1 = H - h0;
			LL w1 = W / 2;
			LL h2 = H - h0;
			LL w2 = W - w1;
			ret = MIN(ret, calc(h0 * w0, h1 * w1, h2 * w2));
		}
		{
			LL h0 = H;
			LL w0 = ceil((double)W / 3);
			LL h1 = H / 2;
			LL w1 = W - w0;
			LL h2 = H - h1;
			LL w2 = W - w0;
			ret = MIN(ret, calc(h0 * w0, h1 * w1, h2 * w2));
		}
		{
			LL h0 = H;
			LL w0 = floor((double)W / 3);
			LL h1 = H / 2;
			LL w1 = W - w0;
			LL h2 = H - h1;
			LL w2 = W - w0;
			ret = MIN(ret, calc(h0 * w0, h1 * w1, h2 * w2));
		}
		{
			LL h = (H < W) ? H : W;
			LL w = (H > W) ? H : W;
			LL h0 = h;
			LL w0 = w / 3;
			LL h1 = h;
			LL w1 = (w - w0) / 2;
			LL h2 = h;
			LL w2 = w - w0 - w1;
			ret = MIN(ret, calc(h0 * w0, h1 * w1, h2 * w2));
		}
	}

	cout << ret << endl;

#if _DEBUG
	cin >> ret;
#endif

	return 0;
}
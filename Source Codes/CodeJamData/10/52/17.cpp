#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s);i--)

#define forall(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define dforall(i,c) for(typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); i++)
#define all(c) (c).begin(),(c).end()

#define esta(x,c) ((c).find(x) != (c).end())
#define zMem(c) memset((c),0,sizeof(c))

typedef long long tint;
typedef long double tdbl;

typedef pair<int,int> pint;
typedef pair<tint,tint> ptint;

typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;

#define INF 0x3F3F3F3F3F3F3F3FLL

#define MAXB 110000
#define MAXN 128

tint dp[MAXB][MAXN];

tint v[MAXN];

tint modu(tint a,tint b)
{
	return ((a%b)+b)%b;
}

int main()
{
	stdin = freopen("b.in","r",stdin);
	stdout = freopen("b.out","w",stdout);
	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
		tint L; cin >> L;
		int n; cin >> n;
		forn(i,n) cin >> v[i];
		sort(v,v+n);
		tint B = v[n-1];
		forn(s,B)
		forn(i,n+1)
			dp[s][i] = INF;
		deque<int> q;
		forn(i,n+1)
		{
			dp[L%B][i] = L/B;
			q.push_back(L%B);
			q.push_back(i);
		}
		while (!q.empty())
		{
			int s = q.front(); q.pop_front();
			int i = q.front(); q.pop_front();
			tint d = dp[s][i];
			if (i<n && d < dp[s][i+1])
			{
				dp[s][i+1] = d;
				q.push_front(i+1);
				q.push_front(s);
			}
			if (i>0)
			{
				int s0 = modu(s-v[i-1],B);
				int costo = 1 - (s0+v[i-1])/B;
				if (d + costo < dp[s0][i])
				{
					dp[s0][i] = d+costo;
					if (costo == 0)
					{
						q.push_front(i);
						q.push_front(s0);
					}
					else
					{
						q.push_back(s0);
						q.push_back(i);
					}
				}
			}
		}
		tint res = dp[0][n];
		cout << "Case #" << caso + 1 << ": ";
		if (res != INF)
			cout << res;
		else
			cout << "IMPOSSIBLE";
		cout<< endl;
		//cerr << "Case #" << caso + 1 << ": " << res << endl;
	}
	return 0;
}


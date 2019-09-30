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

int main()
{
	stdin = freopen("c.in","r",stdin);
	stdout = freopen("c.out","w",stdout);
	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
		int C; cin >> C;
		map<int,int> v;
		forn(i,C)
		{
			int a,b; cin>> a>>b;
			v[a] = b;
		}
		bool sigo = true;
		tint res = 0;
		while (sigo)
		{
			sigo = false;
			forall(it,v)
			if (it->second > 1)
			{
				sigo = true;
				tint s = (it->second)/2;
				int i = it->first;
				v[i-1] += s;
				v[i+1] += s;
				v[i] -= 2*s;
				res += s;
			}
		}
		cout << "Case #" << caso + 1 << ": " << res << endl;
		cerr << "Case #" << caso + 1 << ": " << res << endl;
	}
	return 0;
}


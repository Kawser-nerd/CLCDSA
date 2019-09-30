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

#define INF 1000000000

int main()
{
	freopen("entrada.in","r",stdin);
	freopen("salida.out","w",stdout);
	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
		int C,k;
		cin >> k >> C;
		int res = 0;
		if (C==1) res = k;
		else if (C==2)
		{
			res = INF;
			forn(x,k+1)
			forn(y,k+1)
			{
				forn(a,k+1)
				{
					int b = k - a;
					int X = x, Y = y;
					
					if (X < a) goto fuera1;
					X -= a;
					if (X + 2*Y < 2*b) goto fuera1;
					//cerr << x << " " << y << endl;
				}
				res = min(res,x+y);
fuera1:;
			}
		}
		else
		{
			res = INF;
			forn(x,k+1)
			forn(y,k+1)
			forn(z,k+1)
			{
				forn(a,k+1)
				forn(b,k+1 - a)
				{
					int c = k - a - b;
					int X = x, Y = y,Z = z;
					
					if (X < a) goto fuera2;
					X -= a;
					if (Z < c) c -= Z;
					else c = 0;
					if (X < c) goto fuera2;
					X -= c;
					b += c;
					if (X + 2*Y < 2*b) goto fuera2;
				}
				res = min(res,x+y+z);
fuera2:;
			}
		}
		cout << "Case #" << caso + 1 << ": " << res << endl;
		cerr << "Case #" << caso + 1 << ": " << res << endl;
	}
	return 0;
}

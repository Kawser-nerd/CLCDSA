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

const tint MOD = 1000000007;

int B;
int N;

int u[16][16];

tint go(int x)
{
	if (N==0) return 1;
	tint res = 0;
	forsn(i,x,N+1)
	{
		bool anda = true;
		int z = i,p=0;
		while (z != 0)
		{
			if (u[z%B][p])
			{
				anda = false;
				break;
			}
			z /= B;
			p++;
		}
		if (anda)
		{
			z = i,p=0;
			while (z != 0)
			{
				u[z%B][p] = 1;
				z /= B;
				p++;
			}
			N -= i;
			res += go(i+1);
			N += i;
			z = i,p=0;
			while (z != 0)
			{
				u[z%B][p] = 0;
				z /= B;
				p++;
			}
		}
	}
	return res;
}

int main()
{
	stdin = freopen("d.in","r",stdin);
	stdout = freopen("d.out","w",stdout);
	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
		zMem(u);
		cin >> N >> B;
		tint res = go(1);
		cout << "Case #" << caso + 1 << ": " << res << endl;
		cerr << "Case #" << caso + 1 << ": " << res << endl;
	}
	return 0;
}


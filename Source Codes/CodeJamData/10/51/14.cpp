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

#define MAX 10000000

int p[MAX];

void criba()
{
	forn(i,MAX) p[i] = 1;
	p[0] = p[1] = 0;
	for(int i=2;i*i<MAX;i++)
	if (p[i])
		for(int j=i*i;j<MAX;j+=i) p[j] = 0;
}

int pot10[10];

tint mcd(tint a, tint b){ return (a==0)?b:mcd(b%a, a);}
struct dxy {tint d,x,y;};
dxy mcde(tint a, tint b) {
  dxy r, t;
  if (b == 0) {
    r.d = a; r.x = 1; r.y = 0;
  } else {
    t = mcde(b,a%b);
    r.d = t.d; r.x = t.y;
    r.y = t.x - a/b*t.y;
  }
  return r;
}

tint modu(tint a,tint b)
{
	return ((a%b)+b)%b;
}

int main()
{
	pot10[0] = 1;
	forn(i,9) pot10[i+1] = pot10[i] * 10;
	criba();
	stdin = freopen("a.in","r",stdin);
	stdout = freopen("a.out","w",stdout);
	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
		int d,k; cin >> d >> k;
		vint v(k);
		forn(i,k) cin >> v[i];
		cout << "Case #" << caso + 1 << ": ";
		if (k==1 || (k==2 && v[0] != v[1]))
			cout << "I don't know.";
		else
		{
			if (v[0] == v[1]) cout << v[0];
			else
			{
				set<int> resultados;
				int base = 1 + *max_element(all(v));
				// k>=3
				forsn(i,base,pot10[d])
				if (p[i])
				{
					tint X = v[1], S = v[0], Y = v[2];
					dxy r = mcde(modu(X-S,i),i);
					tint inv = modu(r.x,i);
					tint A = modu((Y-X)*inv,i);
					tint B = modu(X - S * A,i);
					tint ac = S;
					bool anda = true;
					forn(j,k)
					{
						if (ac != v[j])
						{
							anda = false;
							break;
						}
						ac = modu(ac*A + B,i);
					}
					if (anda) 
					{
						resultados.insert(ac);
					}
				}
				if (resultados.size() > 1)
					cout << "I don't know.";
				else
					cout << *resultados.begin();
			}
		}
		cout << endl;
		//cerr << "Case #" << caso + 1 << ": " << res << endl;
	}
	return 0;
}

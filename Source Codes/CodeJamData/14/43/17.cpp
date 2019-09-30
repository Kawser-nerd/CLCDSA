#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <ctime>
#include <bitset>
using namespace std;

#pragma comment(linker, "/stack:64000000")

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int > > vii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ld> vld;

typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vs> vvs;

typedef map<int, int> mpii;
typedef map<int, string> mpis;
typedef map<string, int> mpsi;
typedef map<string, string> mpss;

#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(a) (int)((a).size())
#define len(a) (int)((a).length())

#define forr(i,n) for (int i = 0; i < (n); ++i)
#define fori(n) forr(i,n)
#define forj(n) forr(j,n)
#define fork(n) forr(k,n)
#define forin fori(n)
#define forjn forj(n)
#define forjm forj(m)
#define forkm fork(m)
#define foria(a) fori(sz(a))
#define foriv foria(v)
#define foris fori(len(s))
#define forja(a) forj(sz(a))
#define forjv forj(v)
#define forjs forj(len(s))

#define read cin>>
#define write cout<<
#define writeln write endl

#define readt int aaa; read aaa;
#define gett (bbb+1)
#define fort forr(bbb,aaa)

#define issa(a,s) istringstream a(s);
#define iss(s) issa(ss,s);

ld dis(ld x, ld y) {return sqrt(x*x+y*y);}
const ld PI = acos(ld(0.0))*2;

ll gcd(ll a, ll b){return b ? gcd(b,a%b) : a;}

template<class T>
struct makev
{
    vector<T> v;
    makev& operator << (const T& x)
    {
        v.push_back(x);
        return *this;
    }
    operator vector<T>& ()
    {
        return v;
    }
};

void assert(bool b)
{
    if (!b)
        throw 0;
}

template <int n>
struct nbest
{
    vector<pair<ll, int> > p;
    nbest():p(n+1)
    {
        foria(p) p[i].first = p[i].second = -1;
    }
    void add(ll value, int key)
    {
        p[n] = make_pair(value, key);
        sort(rall(p));
    }
    ll getValue(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].first;
    }
    int getKey(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].second;
    }
    bool has(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].second != -1;
    }
};

/*vector<int> yScaled;
vector<int> yScaleWidth;
int mp[2000][5000];*/
int w, h, n;

struct rect
{
	ll x1, x2;
	ll y1, y2;
	bool intersects(rect other)
	{
		ll minx = max(x1, other.x1), maxx = min(x2, other.x2);
		ll miny = max(y1, other.y1), maxy = min(y2, other.y2);
		return minx <= maxx && miny <= maxy;
	}
	ll dist(rect other)
	{
		ll step = 1LL << 33;
		ll cur = 0;
		while (step)
		{
			ll test = cur + step;
			rect rtest = other;
			rtest.x1 -= test;
			rtest.x2 += test;
			rtest.y1 -= test;
			rtest.y2 += test;
			if (!intersects(rtest))
				cur = test;

			step >>= 1;
		}
		return cur;
	}

	/*void populate()
	{
		yScaled.push_back(y1);
		yScaled.push_back(y2 + 1);
	}
	void update()
	{
		++x2;
		y1 = lower_bound(all(yScaled), y1) - yScaled.begin();
		y2 = lower_bound(all(yScaled), y2 + 1) - yScaled.begin();
	}
	void draw()
	{
		for (int i = x1; i < x2; i++)
			for (int j = y1; j < y2; j++)
				mp[i + 1][j] = 1;
	}*/
};
const int MAX_VTX = 2000;
vector<pair<int, ll> > g[MAX_VTX];

void addEdge(int from, int to, ll c)
{
	g[from].push_back(make_pair(to, c));
	g[to].push_back(make_pair(from, c));
}
/*void addEdge2(int from, int to, int c)
{
	g[to].push_back(ii(from, c));
}

int vtx(int i, int j, bool plus)
{
	if (i == 0 || i == w + 1)
	{
		j = 0;
		plus = 0;
	}
	return (i * sz(yScaled) + j) * 2 + 1 + plus;
}

void build()
{
	fori(MAX_VTX) g[i].clear();
	for (int j = 0; j + 1 < sz(yScaled); j++)
		mp[0][j] = mp[w+1][j] = 1;

	for (int i = 1; i <= w; i++)
		for (int j = 0; j + 1 < sz(yScaled); j++)
		{
			int y1 = yScaled[j];
			int y2 = yScaled[j+1] - 1;
			addEdge(vtx(i - 1, j, 0), vtx(i, j, 0), 1 - mp[i][j]);
			addEdge2(vtx(i - 1, j, 0), vtx(i, j, 0), 1 - mp[i-1][j]);
			addEdge(vtx(i - 1, j, 1), vtx(i, j, 1), 1 - mp[i][j]);
			addEdge2(vtx(i - 1, j, 1), vtx(i, j, 1), 1 - mp[i-1][j]);

			addEdge(vtx(i + 1, j, 0), vtx(i, j, 0), 1 - mp[i][j]);
			addEdge2(vtx(i + 1, j, 0), vtx(i, j, 0), 1 - mp[i+1][j]);
			addEdge(vtx(i + 1, j, 1), vtx(i, j, 1), 1 - mp[i][j]);
			addEdge2(vtx(i + 1, j, 1), vtx(i, j, 1), 1 - mp[i+1][j]);

			addEdge(vtx(i, j, 0),  vtx(i, j, 1), (1 - mp[i][j]) * (y2 - y1));
			addEdge2(vtx(i, j, 0),  vtx(i, j, 1), (1 - mp[i][j]) * (y2 - y1));
			if (j != 0)
			{
				addEdge(vtx(i, j - 1, 1),  vtx(i, j, 0), (1 - mp[i][j]));
				addEdge2(vtx(i, j - 1, 1),  vtx(i, j, 0), (1 - mp[i][j-1]));
			}
			if (j + 2 < sz(yScaled))
			{
				addEdge(vtx(i, j + 1, 0),  vtx(i, j, 1), (1 - mp[i][j]));
				addEdge2(vtx(i, j + 1, 0),  vtx(i, j, 1), (1 - mp[i][j+1]));
			}
		}
}*/

ll dijkstra(int from, int to)
{
	vector<ll> d (MAX_VTX, 10000000000LL),  p (MAX_VTX);
	d[from] = 0;
	vector<char> u (MAX_VTX);
	for (int i=0; i<MAX_VTX; ++i) {
		int v = -1;
		for (int j=0; j<MAX_VTX; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == 10000000000LL)
			break;
		u[v] = true;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first;
			ll len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
	return d[to];
}


int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	readt;
	fort
	{
		read w >> h >> n;
		vector<rect> v(n);
		forin
		{
			read v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
		}

		rect start, end;
		start.x1 = start.x2 = -1;
		start.y1 = 0;
		start.y2 = h - 1;
		end.x1 = end.x2 = w;
		end.y1 = 0;
		end.y2 = h - 1;
		v.insert(v.begin(), start);
		v.push_back(end);

		fori(MAX_VTX) g[i].clear();
		fori(n+2) forj(n+2) if (i < j)
			addEdge(i, j, v[i].dist(v[j]));

		ll ans = dijkstra(0, n + 1);

		cout << "Case #" << gett << ": " << ans << endl;
		std::cout << "Case #" << gett << ": " << ans << endl;
	}

	return 0;
}
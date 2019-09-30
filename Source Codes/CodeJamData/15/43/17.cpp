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

map<string, int> name;

int graph[10000][10000];

void inittest()
{
	name.clear();
	memset(graph, 0, sizeof(graph));
}

inline int downndx(int x)
{
	return x * 2 + 2;
}

inline int upndx(int x)
{
	return x * 2 + 2 + 1;
}

inline int maxname()
{
	//return 9000;
	return downndx(sz(name));
}

int getName(string s)
{
	if (name.count(s) == 0)
	{
		int x = sz(name);
		name[s] = x;
		graph[downndx(x)][upndx(x)] = 1;
		return x;
	}
	return name[s];
}

bool visit[10000];

int dfs(int x, int mv)
{
	if (x == 1)
		return mv;

	if (visit[x])
		return 0;
	visit[x] = true;

	int n = maxname();
	forin if (graph[x][i])
	{
		int c = dfs(i, min(mv, graph[x][i]));
		if (c != 0)
		{
			graph[x][i] -= c;
			graph[i][x] += c;
			visit[x] = false;
			return c;
		}
	}
	return 0;
}

int solve()
{
	int ans = 0;
	while (1)
	{
		int c = dfs(0, 10000000);
		if (c == 0)
		{
			memset(visit, 0, sizeof(visit));
			c = dfs(0, 10000000);
			if (c == 0)
				return ans;
		}
		ans += c;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
#ifdef _MSC_VER
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#else
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
#endif

	cout.setf(ios::fixed);
	cout.precision(20);

	readt;
	fort
	{
		inittest();
		int n;
		read n;
		string s;
		getline(cin, s);
		forin
		{
			vi v;
			getline(cin, s);
			istringstream istr(s);
			string s2;
			while (istr >> s2)
			{
				v.push_back(getName(s2));
			}

			/*if (i == 0)
			{
				v.resize(1000);
				foriv v[i] = i;
			}
			else if (i == 1)
			{
				v.resize(1000);
				foriv v[i] = i;
			}
			else
			{
				v.resize(10);
				forja(v) v[j] = i * 10 + 2000;
			}
			forj(4000) graph[downndx(j)][upndx(j)] = 1;*/

			foriv forja(v) if (v[i] != v[j])
			{
				graph[upndx(v[i])][downndx(v[j])] = 1;
			}

			if (i == 0)
			{
				forja(v)
					graph[0][downndx(v[j])] = 1000000;
			}
			else if (i == 1)
			{
				forja(v)
					graph[upndx(v[j])][1] = 1000000;
			}
		}

		int ans = solve();
		cout << "Case #" << gett << ": " << ans << endl;
		std::cout << "Case #" << gett << ": " << ans << endl;
	}

	return 0;
}
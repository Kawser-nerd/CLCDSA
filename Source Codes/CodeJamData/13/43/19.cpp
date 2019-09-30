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

const ll mod = 1000002013LL;

ll addmod(ll x, ll y)
{
	ll result = x + y;
	while (result >= mod)
		result -= mod;
	return result;
}
ll submod(ll x, ll y)
{
	ll result = x - y;
	while (result < 0)
		result += mod;
	while (result >= mod)
		result -= mod;
	return result;
}
ll mulmod(ll x, ll y)
{
	x %= mod;
	y %= mod;
	return (x * y) % mod;
}
ll cost(ll n, ll dist)
{
	return submod(mulmod(n, dist), (dist * (dist - 1) / 2) % mod);
}

vi visit;
vvi graph;
vi number;
int ncnt;

void DFS(int x)
{
	if (visit[x])
		return;
	visit[x] = true;

	sort(all(graph[x]));
	foria(graph[x])
		DFS(graph[x][i]);
	number[x] = ncnt;
	++ncnt;
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	readt;
	fort
	{
		int n;
		read n;
		visit.assign(n, 0);
		graph.assign(n, vi());
		number.assign(n, 0);
		ncnt = 1;

		vi a(n), b(n);
		forin read a[i];
		forin read b[i];

		forin
		{
			int last = -1;
			forj(i)
			{
				if (a[j] >= a[i])
					graph[j].push_back(i);
				if (a[j] + 1 == a[i])
					last = j;
			}
			if (last != -1)
				graph[i].push_back(last);
			else
				assert(a[i] == 1);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			int last = -1;
			for (int j = n - 1; j > i; j--)
			{
				if (b[j] >= b[i])
					graph[j].push_back(i);
				if (b[j] + 1 == b[i])
					last = j;
			}
			if (last != -1)
				graph[i].push_back(last);
			else
				assert(b[i] == 1);
		}

		forin DFS(i);

		write "Case #" << gett << ":";
		foria(number)
			write ' ' << number[i];
		cout << endl;
		//std::cout <<  "Case #" << gett << ": " << ans << endl;
	}
}
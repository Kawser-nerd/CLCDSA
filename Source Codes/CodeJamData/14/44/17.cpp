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
int m;

const ll MOD = 1000000007;

ll c[300][300];

void init()
{
	c[0][0] = 1;
	fori(200) forj(200) if (i + 1 >= j)
	{
		if (j == 0)
			c[i + 1][j] = 1;
		else
			c[i + 1][j] = (c[i][j] + c[i][j-1]) % MOD;
	}
}

struct trie
{
	int subcnt;
	ll result;
	ll result2;
	bool mark_;
	trie():subcnt(0), mark_(false){}
	~trie()
	{
		foria(elements) delete elements[i].second;
		elements.clear();
	}
	std::vector<pair<char, trie* > > elements;
	trie *selectAlways(char c)
	{
		foria (elements) if (elements[i].first == c) return elements[i].second;
		elements.push_back(make_pair(c, new trie()));
		return elements.back().second;
	}
	void mark()
	{
		trie *p = selectAlways(0);
		p->mark_ = true;
		p->subcnt = 1;
	}
	void dfs1()
	{
		result2 = 0;
		if (mark_)
		{
			result = 1;
			return;
		}
		foria(elements) 
		{
			elements[i].second->dfs1();
			subcnt += elements[i].second->subcnt;
			if (!elements[i].second->mark_)
				result2 += elements[i].second->result2;
		}
		result2 += min(m, subcnt);

		int maxe = min(m, subcnt);
		vll dp(maxe + 1, 0);
		dp[maxe] = 1;
		foria(elements)
		{
			vll dp2(maxe + 1, 0);
			int cwant = min(m, elements[i].second->subcnt);
			for (int k = 0; k <= maxe; k++)
			{
				for (int j = 0; j <= cwant && j <= k; j++)
				{
					ll c1 = c[k][j]; //were not before
					ll c2 = c[maxe - k][cwant - j]; //were before

					ll dr = 1; //dp[k] * elements[i].second->result * c1 * c2
					dr *= dp[k];
					dr %= MOD;
					dr *= elements[i].second->result;
					dr %= MOD;
					dr *= c1;
					dr %= MOD;
					dr *= c2;
					dr %= MOD;

					dp2[k - j] += dr;
					dp2[k - j] %= MOD;
				}
			}
			dp.swap(dp2);
		}
		result = dp[0];
	}
} *root;

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	
	init();

	readt;
	fort
	{
		int n;
		read n >> m;
		vs v(n);
		forin read v[i];

		root = new trie();

		forin 
		{
			trie *current = root;
			forja(v[i]) current = current->selectAlways(v[i][j]);
			current->mark();
		}

		root->dfs1();
		
		ll ans2 = root->result;
		ll ans1 = root->result2;

		cout << "Case #" << gett << ": " << ans1 << " " << ans2 << endl;
		std::cout << "Case #" << gett << ": " << ans1 << " " << ans2 << endl;

		delete root;
	}

	return 0;
}
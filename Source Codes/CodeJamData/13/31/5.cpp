/**
 * Blunt, break!
 * Actual solution is very slow
 * @author Slow Poke (slowpoke@localhost)
 */
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

int main()
{
#ifdef _MSC_VER
	ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	ofstream cout("output.txt");
#else
	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");
#endif

	readt;
	fort
	{
		int t;
		string s;
		read s;
		read t;
		ll ans = 0;

		int j = 0;
		multiset<int> mst;
		deque<int> v;
		for (int i = 0; i < len(s); i++) 
		{
			int cur = sz(v) ? v.back() : 0;
			auto it = mst.end();
			int test = 0;
			if (it != mst.begin())
			{
				--it;
				test = *it;
			}
			while (test < t)
			{
				if (j < len(s))
				{
					if (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u') 
					{
						if (cur)
						{
							mst.erase(mst.find(cur));
						}
						else
						{
							v.push_back(0);
						}
						++cur;
						++v.back();
						mst.insert(cur);
					}
					else
					{
						v.push_back(0);
						cur = 0;
					}
					++j;
				}
				else 
				{
					break;
				}			
				auto it = mst.end();
				if (it != mst.begin())
				{
					--it;
					test = *it;
				}
			}
			if (test >= t)
			{
				ans += ((int)s.length() - j + 1);
			}
			else
			{
				break;
			}
			if (v[0] == 0)
			{
				v.pop_front();
			}
			else
			{
				int c = v[0];
				mst.erase(mst.find(c));
				--c;
				v.pop_front();
				if (c)
				{
					v.push_front(c);
					mst.insert(c);
				}
			}
		}

		cout << "Case #" << gett << ": " << ans << endl;
		std::cout << "Case #" << gett << ": " << ans << endl;
	}

	return 0;
}
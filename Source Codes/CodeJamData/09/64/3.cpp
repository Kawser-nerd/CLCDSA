#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define PB push_back
#define M_PI       3.14159265358979323846
#define eps 1.0e-11

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

template <typename T>
class Point
{
public:
	T x,y;
	Point() {};
	Point(T _x,T _y) : x(_x),y(_y) {}
	void read() { scanf("%d%d",&x,&y); }
	void swap() { swap(x,y); }
	double len();
	Point<double> asDouble() { return Point<double>(x,y); }
	Point<T> norm();
};

template <typename T> Point<T> operator+ (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x+b.x,a.y+b.y); }
template <typename T> Point<T> operator- (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x-b.x,a.y-b.y); }
template <typename T> Point<T> operator* (const T a, const Point<T> &b) { return Point<T>(a*b.x,a*b.y); }
template <typename T> Point<T> operator* (const Point<T> &b, const T a) { return Point<T>(a*b.x,a*b.y); }
template <typename T> T operator* (const Point<T> &a, const Point<T> &b) { return a.x*b.x+a.y*b.y; }
template <typename T> T operator^ (const Point<T> &a, const Point<T> &b) { return a.x*b.y-a.y*b.x; }
template <typename T> double Point<T>::len() { return sqrt((*this)*(*this)); }
template <typename T> Point<T> Point<T>::norm() { return (1.0/len())*(*this); }

bool operator== (const Point<int> &a, const Point<int> &b) { return a.x==b.x && a.y==b.y; }
bool operator< (const Point<int> &a, const Point<int> &b) { return a.x<b.x || a.x==b.x && a.y<b.y; }
bool operator!= (const Point<int> &a, const Point<int> &b) { return a.x!=b.x || a.y!=b.y; }

#define NAME "D-small-attempt0"
#define N 512

int n;
Point<int> a[N];
int r[N],score[N];
bool bl[N][N];

int stupid()
{
	int res=0;
	REP(mask,1<<n)
	{
		bool bad=false;
		REP(i,n) if (mask&(1<<i))
			REP(j,n) if (!(mask&(1<<j)) && bl[i][j])
				bad=true;
		if (!bad)
		{
			int cur=0;
			REP(i,n) if (mask&(1<<i))
				cur+=score[i];
			res=max(res,cur);
		}
	}
	return res;
}

int main()
{
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	REP(tst,tests)
	{
		fprintf(stderr,"Test #%d\n",tst+1);
		scanf("%d",&n);
		REP(i,n)
		{
			a[i].read();
			scanf("%d%d",r+i,score+i);
		}
		CLEAR(bl);
		REP(i,n) REP(j,n) if (i!=j)
			bl[i][j] = (a[i]-a[j])*(a[i]-a[j]) <= r[i]*r[i];
		int res=stupid();

		printf("Case #%d: %d\n",tst+1,res);
	}
	return 0;
}
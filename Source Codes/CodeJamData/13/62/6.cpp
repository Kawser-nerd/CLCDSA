#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
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
#include <cassert>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

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
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

template <typename T> struct Point {
	T x,y;
	Point(T _x=0,T _y=0) : x(_x),y(_y) {}
	void read();
	void swap() { swap(x,y); }
	double len() const;
	Point<double> asDouble() { return Point<double>(x,y); }
	Point<T> norm() const;
	Point<T> ort() const { return Point<T>(y,-x); }
};
template<> void Point<int>::read() { scanf("%d%d",&x,&y); }
template<> void Point<double>::read() { scanf("%lf%lf",&x,&y); }
template <typename T> Point<T> operator- (const Point<T> &a) { return Point<T>(-a.x,-a.y); }
template <typename T> Point<T> operator+ (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x+b.x,a.y+b.y); }
template <typename T> Point<T> operator- (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x-b.x,a.y-b.y); }
template <typename T> Point<T> operator* (const T a, const Point<T> &b) { return Point<T>(a*b.x,a*b.y); }
template <typename T> Point<T> operator* (const Point<T> &b, const T a) { return Point<T>(a*b.x,a*b.y); }
template <typename T> Point<T> operator/ (const Point<T> &b, const T a) { return Point<T>(b.x/a,b.y/a); }
template <typename T> T operator* (const Point<T> &a, const Point<T> &b) { return a.x*b.x+a.y*b.y; }
template <typename T> T operator^ (const Point<T> &a, const Point<T> &b) { return a.x*b.y-a.y*b.x; }
template <typename T> double Point<T>::len() const { return sqrt((double)((*this)*(*this))); }
template <typename T> Point<T> Point<T>::norm() const { return (*this)/len(); }
template <typename T> bool operator< (const Point<T> &a, const Point<T> &b) { return a.x<b.x || a.x==b.x && a.y<b.y; }
bool operator== (const Point<int> &a, const Point<int> &b) { return a.x==b.x && a.y==b.y; }
bool operator!= (const Point<int> &a, const Point<int> &b) { return a.x!=b.x || a.y!=b.y; }
int sign(int x) { if (x==0) return 0; if (x>0) return +1; else return -1; }
int sign(double x) { if (fabs(x)<eps) return 0; if (x>0) return +1; else return -1; }
template<typename T> T sqr(T x) { return x*x; }
typedef Point<double> DPnt;
typedef Point<int> IPnt;
const DPnt INFDPnt(1.0e30,1.0e30);

vector<IPnt> ConvexHull(vector<IPnt> a) {
	vector<IPnt> hull;
	REP(i,SZ(a)) {
		while (SZ(hull)>=2 && ((a[i]-hull.back())^(hull.back()-hull[SZ(hull)-2])) <= 0)
			hull.pop_back();
		hull.push_back(a[i]);
	}
	return hull;
}


#define N 55000
int n;
IPnt a[N];

double get(IPnt a, IPnt b, int x)
{
	return a.y + (b.y-a.y)/(double)(b.x-a.x)*(x-a.x);
}

int main(int argc, char **argv)
{
	string FN = "B-small-attempt0";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%d",&n);
		REP(i,n) {
			a[i].x = i;
			scanf("%d",&a[i].y);
		}

		vector<IPnt> top = ConvexHull(vector<IPnt>(a,a+n));
		vector<IPnt> rev(a,a+n);
		reverse(ALL(rev));
		vector<IPnt> bottom = ConvexHull(rev);
		reverse(ALL(bottom));
		swap(top,bottom);
		int itop=0,ibottom=0;
		double res=0;
		REP(i,n)
		{
			while (itop+2 < SZ(top) && top[itop+1].x < i) ++itop;
			while (ibottom+2 < SZ(bottom) && bottom[ibottom+1].x < i) ++ibottom;
			double ytop = get(top[itop], top[itop+1], i);
			double ybottom = get(bottom[ibottom], bottom[ibottom+1], i);
			res = max(res,ybottom-ytop);
		}
		res/=2;
		printf("%.12lf\n",res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}
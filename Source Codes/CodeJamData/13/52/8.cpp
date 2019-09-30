#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Vector
{
	double x, y;
	
	Vector(double a = 0.0, double b = 0.0): x(a), y(b) { }
	Vector(const Vector & v): x(v.x), y(v.y) { }

	Vector & operator=(const Vector & v) { x = v.x; y = v.y; return *this; }
	Vector operator+(const Vector & v) const { return Vector(x + v.x, y + v.y); }
	Vector & operator+=(const Vector & v) { x += v.x; y += v.y; return *this; }
	Vector operator-(const Vector & v) const { return Vector(x - v.x, y - v.y); }
	Vector & operator-=(const Vector & v) { x -= v.x; y -= v.y; return *this; }
	Vector operator*(double n) const { return Vector(x * n, y * n); }
	Vector & operator*=(double n) { x *= n; y *= n; return *this; }
	Vector operator/(double n) const { return Vector(x / n, y / n); }
	Vector & operator/=(double n) { x /= n; y /= n; return *this; }

	bool operator==(const Vector & v) const { return EQ(x, v.x) && EQ(y, v.y); }
	bool operator!=(const Vector & v) const { return !EQ(x, v.x) || !EQ(y, v.y); }
	bool operator<(const Vector & v) const { return x < v.x || (EQ(x, v.x) && y < v.y); }

	double size() const { return sqrt(x*x + y*y); }
	double size2() const { return x*x + y*y; }
	double angle() const { return atan2(y, x); }
};

inline double dot_product(const Vector & v1, const Vector & v2) 
	{ return v1.x * v2.x + v1.y * v2.y; }

inline double cross_product(const Vector & v1, const Vector & v2) 
	{ return v1.x * v2.y - v1.y * v2.x; }

inline double direction(const Vector & segment1, const Vector & segment2, const Vector & point) 
	{ return cross_product(point - segment1, segment2 - segment1); }

inline bool on_segment(const Vector & segment1, const Vector & segment2, const Vector & point)
	{ return min(segment1.x, segment2.x) <= point.x && point.x <= max(segment1.x, segment2.x) && min(segment1.y, segment2.y) <= point.y && point.y <= max(segment1.y, segment2.y); }

inline bool collinear(const Vector & point1, const Vector & point2, const Vector & point3)
	{ return EQ((point2.x - point1.x) * (point3.y - point1.y), (point3.x - point1.x) * (point2.y - point1.y)); }

// intersection of two line segments (endpoints including)
bool intersect(const Vector & segment1, const Vector & segment2, const Vector & segment3, const Vector & segment4)
{
	double dir1 = direction(segment3, segment4, segment1),
		dir2 = direction(segment3, segment4, segment2),
		dir3 = direction(segment1, segment2, segment3),
		dir4 = direction(segment1, segment2, segment4);
	if (dir1 * dir2 < 0.0 && dir3 * dir4 < 0.0) return true;
	// check the endpoints
	if (EQ(dir1, 0.0) && on_segment(segment3, segment4, segment1)) return true;
	if (EQ(dir2, 0.0) && on_segment(segment3, segment4, segment2)) return true;
	if (EQ(dir3, 0.0) && on_segment(segment1, segment2, segment3)) return true;
	if (EQ(dir4, 0.0) && on_segment(segment1, segment2, segment4)) return true;
	return false;
}

double count_area(const vector<Vector> & polygon)
{
	double res = 0.0;
	for (int i = 0; i < polygon.size(); ++i)
		res += cross_product(polygon[i], polygon[(i+1) % polygon.size()]);
	return fabs(res) / 2.0;
}

void convex_hull(vector<Vector> & points, vector<Vector> & hull)
{
	sort(points.begin(), points.end());
	vector<Vector> top, bot;
	for (int i = 0; i < points.size(); ++i)
	{
		while (top.size() >= 2 && direction(top[top.size()-2], points[i], top[top.size()-1]) <= 0)
			top.pop_back();
		top.push_back(points[i]);
		while (bot.size() >= 2 && direction(bot[bot.size()-2], points[i], bot[bot.size()-1]) >= 0)
			bot.pop_back();
		bot.push_back(points[i]);
	}
	reverse(bot.begin(), bot.end());
	hull = top;
	if (bot.size() > 2) hull.insert(hull.end(), bot.begin()+1, bot.end()-1);
}

const int MAX = 10;
int N;
Vector in[MAX];

void Solve(int tc)
{
	scanf("%d", &N);
	REP(i, N)
	{
		scanf("%lf %lf", &in[i].x, &in[i].y);
	}

	vector<Vector> points, hull;
	REP(i, N) points.push_back(in[i]);
	convex_hull(points, hull);
	double opt = count_area(hull);

	printf("Case #%d:", tc);
	vector<int> v;
	REP(i, N) v.push_back(i);
	do
	{
		 bool ok = true;
		 REP(i, N) FOR(j, i+1, N-1)
		 {
			 int a = v[i], b = v[(i+1)%v.size()],
				 c = v[j], d = v[(j+1)%v.size()];
			 if (a != c && a != d && b != c && b != d && intersect(in[a], in[b], in[c], in[d]))
			 {
				 ok = false;
				 break;
			 }
		 }

		 if (ok)
		 {
			 points.clear();
			 REP(i, N) points.push_back(in[v[i]]);
			 double a = count_area(points);
			 if (2*a > opt)
			 {
				 REP(i, N)
					printf(" %d", v[i]);
				 printf("\n");
				 return;
			 }
		 }
	} while (next_permutation(v.begin()+1, v.end()));
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}
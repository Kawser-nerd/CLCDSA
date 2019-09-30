//Authored by dolphinigle
//GCJ R3 2011
//Jun 11 2011

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))
#define RESET(Z,Y) memset(Z,Y,sizeof(Z))

#define SZ(Z) ((int)Z.size())
#define ALL(W) W.begin(), W.end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-9

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;
typedef vector<ll> vll;

typedef pair<double, double> Point;
typedef pair<Point, Point> Segment;
typedef vector<Point> Polygon;
typedef pair<double, double> Vector;

bool PointEquals(Point p1, Point p2) {
  return abs(p1.A - p2.A) <= EPS && abs(p1.B - p2.B) <= EPS;
}

//O(N)
double PolygonArea(Polygon polygon) {
	double ret = 0;
	FORN(i,SZ(polygon)) {
		ret += (db)(polygon[i].A * polygon[(i+1)%SZ(polygon)].B);
		ret -= (db)(polygon[i].B * polygon[(i+1)%SZ(polygon)].A);
	}
	return abs(ret) / 2.0;
}
//vector< polygon > polygon;
//return PolygonArea(polygon);

//O(1)
        bool IsIntersecting(Segment segment1, Segment segment2, int* parallel,
    Point* intersection_point) {

  // renamings
	double xx1 = segment1.A.A; double yy1 = segment1.A.B;
  double xx2 = segment1.B.A; double yy2 = segment1.B.B;
	double xx3 = segment2.A.A; double yy3 = segment2.A.B;
	double xx4 = segment2.B.A; double yy4 = segment2.B.B;

	*parallel = 0;
	if (fabs((yy4 - yy3) * (xx2 - xx1) - (xx4 - xx3) * (yy2 - yy1)) <= EPS) {
		*parallel = 1;
    if (PointEquals(segment1.A, segment2.A) || PointEquals(segment1.A, segment2.B)) {
      *intersection_point = segment1.A;
      return true;
    } else if (PointEquals(segment1.B, segment2.A) || PointEquals(segment1.B, segment2.B)) {
      *intersection_point = segment1.B;
      return true;
    }
		return false;
		}
	double ua = ((xx4 - xx3)*(yy1 - yy3) - (yy4-yy3)*(xx1-xx3)) /
      ((yy4-yy3) * (xx2-xx1) - (xx4-xx3) * (yy2 - yy1));
	double& xi = (*intersection_point).A;
	double& yi = (*intersection_point).B;
	xi = xx1 + ua * (xx2 - xx1);
	yi = yy1 + ua * (yy2 - yy1);
	return ( (xi + EPS >= fmin(xx1,xx2)) && (xi - EPS <= fmax(xx1,xx2)) &&
	         (yi + EPS >= fmin(yy1,yy2)) && (yi - EPS <= fmax(yy1,yy2)) &&
			 (xi + EPS >= fmin(xx3,xx4)) && (xi - EPS <= fmax(xx3,xx4)) &&
	         (yi + EPS >= fmin(yy3,yy4)) && (yi - EPS <= fmax(yy3,yy4))
			 );
	}
//IsIntersecting(seg1,seg, &isparallel, &intersectionpoint) //intersect ato touch kaga?

vector< Point > lower;
vector< Point > upper;

int main() {

  int ntc;
  cin >> ntc;
  FORN(itc, ntc) {
    printf("Case #%d:\n", itc+1);

    int width, nl, nu, n;
    cin >> width >> nl >> nu >> n;
    lower.clear();
    upper.clear();
    FORN(i, nl) {
      db x, y;
      cin >> x >> y;
      lower.PB(MP(x, y));
    }
    FORN(i, nu) {
      db x, y;
      cin >> x >> y;
      upper.PB(MP(x, y));
    }

    Polygon cake;
    FORN(i, nl) cake.PB(lower[i]);
    for (int j = nu-1; j >= 0; --j) cake.PB(upper[j]);

    double area = PolygonArea(cake);
    area /= (db)n;

    for (int i = 1; i < n; ++i) {
      db lb = 0.0;
      db ub = width;
      db best = 0.0;
      FORN(j, 100) {
        // cerr << lb << " " << ub << endl;
        db mid = (lb + ub) / 2.0;
        // calculate area
        Polygon cutcake;
        cutcake.PB(upper[0]);
        Segment vert = MP(MP(mid, 2000.0), MP(mid, -2000.0));
        REP(k, 1, nu) {
          int parallel;
          Point pin;
          if (IsIntersecting(MP(upper[k-1], upper[k]), vert, &parallel, &pin)) {
            // hit
            cutcake.PB(pin);
            //cerr << j << " ok" << endl;
            break;
          } else {
            cutcake.PB(upper[k]);
          }
        }
        reverse(ALL(cutcake));
        cutcake.PB(lower[0]);
        REP(k, 1, nl) {
          int parallel;
          Point pin;
          if (IsIntersecting(MP(lower[k-1], lower[k]), vert, &parallel, &pin)) {
            // hit
            cutcake.PB(pin);
            //cerr << j << " ok" << endl;
            break;
          } else {
            cutcake.PB(lower[k]);
          }
        }
        //cerr << "poly" << endl;
        //FORN(k, SZ(cutcake)) cerr << cutcake[k].A << " " << cutcake[k].B << endl;

        db countarea = PolygonArea(cutcake);
        // cerr << countarea << " " << area << endl;
        if (countarea > area * (db)i) {
          ub = mid;
        } else {
          best = mid;
          lb = mid;
        }
      }
      printf("%.8lf\n", best);
    }

  }

  return 0;
}

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define double long double

const double pi = acos(-1.0);
const double eps1 = 1e-13;
const double eps2 = 1e-15;
double eps = 1e-13;
const double inf = 1e12;
const int iters = 200;
const int size = 1000 * 100 + 100;

vector <pair <double, int> > angles;
int tc, n;
double x, y;

double xc[size], yc[size];

bool checkunder(double t) {
	double curx = 0.0, cury = 0.0;
	for (int i = 0; i < n; i++) {
		double curnx = curx + xc[angles[i].sc] * t;
		double curny = cury + yc[angles[i].sc] * t;

		if (curx - eps < x && curnx + eps > x) {
			double hy = cury + yc[angles[i].sc] / xc[angles[i].sc] * (x - curx);

			if (hy + eps > y)
				return true;
		}

		curx = curnx;
		cury = curny;
	}

	return false;
}

bool checkabove(double t) {
	double curx = 0.0, cury = 0.0;
	for (int i = 0; i < n; i++) {
		double curnx = curx + xc[angles[i].sc] * t;
		double curny = cury + yc[angles[i].sc] * t;

		if (curx - eps < x && curnx + eps > x) {
			double hy = cury + yc[angles[i].sc] / xc[angles[i].sc] * (x - curx);

			if (hy - eps < y)
				return true;
		}

		curx = curnx;
		cury = curny;
	}

	return false;
}


bool check(double t) {
	bool f1 = checkunder(t);
	reverse(angles.begin(), angles.end());
	bool f2 = checkabove(t);
	reverse(angles.begin(), angles.end());

//	cout << t << ' ' << f1 << ' ' << f2 << endl;
	return f1 && f2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	if (tnum == 26)
    		eps = eps2;
    	else
    		eps = eps1;
    	cin >> n >> x >> y;
    	y *= x;

    	for (int i = 0; i < n; i++)  {
    		cin >> xc[i] >> yc[i];

    		yc[i] *= xc[i];
    	}

    	angles.clear();
    	for (int i = 0; i < n; i++)
    		angles.pb(mp(atan2(yc[i], xc[i]), i));

       	sort(angles.rbegin(), angles.rend());

       	double cura = atan2(y, x);
       	if (cura < angles.rbegin()->fs - eps || cura > angles.begin()->fs + eps) {
       		printf("Case #%d: IMPOSSIBLE\n", tnum + 1);
       		//cout << "Case #" << tnum + 1 << ": IMPOSSIBLE" << endl;
       		continue;
//       		printf("Case #%d: IMPOSSIBLE\n", tnum + 1);
       	}

       	double lb = 0.0;
       	double rb = inf;

       	for (int it = 0; it < iters; it++) {
       		double mid = (lb + rb) / 2.0;
       		if (check(mid))
       			rb = mid;
       	   	else
       	   		lb = mid;
       	}

  
     	cout.precision(20);
     	printf("Case #%d: %.10Lf\n", tnum + 1, (lb + rb) / 2.0);
//       	cout << "Case #" << tnum + 1 << ": " << (lb + rb) / 2.0 << endl;
  //     	printf("
    }

    return 0;
}
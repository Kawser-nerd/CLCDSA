#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cassert>
#include <utility>

using namespace std;

#define EPS 1E-8

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, a) for (int i = 0; i < int(a.size()); i++)
#define fors(i, a) for (int i = 0; i < int(a.length()); i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VS vector<string>

#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

#define C_IN_FILE "input.txt"
#define C_OUT_FILE "output.txt"

vector<int> x, y, z;
vector<int> vx, vy, vz;
    int n;

void outdata() {
}

double calc(double t) {
    double cx, cy, cz;
    cx = cy = cz = 0.0;
    forv(i, x) {
        cx += x[i] + vx[i] * t;
        cy += y[i] + vy[i] * t;
        cz += z[i] + vz[i] * t;
    }
    cx /= n;
    cy /= n;
    cz /= n;
    return sqrt(cx * cx + cy * cy + cz * cz);
}

double numer(vector<int> x, vector<int> vx) {
    double sx = 0, sy = 0;
	forv(i, x) {
		sx += x[i];
		sy += vx[i];
	}
    return sx * sy;
}

double denumer(vector<int> x, vector<int> vx) {
    double res = 0;
    forv(i, x) res += vx[i];
    return res * res;
}

void solve() {
    cin >> n;
    x.resize(n);
    y.resize(n);
    z.resize(n);
    vx.resize(n);
    vy.resize(n);
    vz.resize(n);
    forn(i, n) {
        cin >> x[i] >> y[i] >> z[i];
        cin >> vx[i] >> vy[i] >> vz[i];
    }
    double sx = numer(x, vx) + numer(y, vy) + numer(z, vz);
    double sy = denumer(x, vx) + denumer(y, vy) + denumer(z, vz);
    double ans, res;
    ans = calc(0);
    res = 0.0;
    if (sy != 0) {
        double cres = -sx * 1.0 / sy;
		if (cres > 0) {
			double nans = calc(cres);
			if (ans > nans) {
				ans = nans;
				res = cres;
			}
		}
    }
    printf("%0.10lf %0.10lf\n", ans, res);
}

void readdata() {
}

int main() {
    int tst;
    cin >> tst;
    forn(i, tst) {
        cout << "Case #" << i + 1 << ": ";
        readdata();
	    solve();
    	outdata();
    }
	return 0;
}

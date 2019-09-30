#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m, g;
double w;
double xl[101], xu[101], yl[101], yu[101];

double get (double t) {
	double cur = 0;
	for (int i = 0; i + 1 < m; i++)
		if (xu[i + 1] > t) {
			double s = (yu[i + 1] - yu[i]) / (xu[i + 1] - xu[i]) * (t - xu[i]) + yu[i];
			cur += (t - xu[i]) * (yu[i] + s) / 2;
			break;
		} else { cur += (xu[i + 1] - xu[i]) * (yu[i] + yu[i + 1]) / 2; }
	for (int i = 0; i + 1 < n; i++)
		if (xl[i + 1] > t) {
			double s = (yl[i + 1] - yl[i]) / (xl[i + 1] - xl[i]) * (t - xl[i]) + yl[i];
			cur -= (t - xl[i]) * (yl[i] + s) / 2;
			break;
		} else { cur -= (xl[i + 1] - xl[i]) * (yl[i] + yl[i + 1]) / 2; }
	re cur;
}

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {

	        cin >> w >> n >> m >> g;
		
		for (int i = 0; i < n; i++) cin >> xl[i] >> yl[i];
		for (int i = 0; i < m; i++) cin >> xu[i] >> yu[i];
		
		double all = get (w);
//		printf ("%.10f\n", all);
		printf ("Case #%d:\n", it);
		for (int i = 1; i < g; i++) {
			double need = all / g * i;
			double l = 0, r = w;
			for (int IT = 0; IT < 100; IT++) {
				double s = (l + r) / 2;
//				printf ("%.10f = %.10f\n", s, get (s));
				if (get (s) > need) r = s; else l = s;
			}
			printf ("%.10f\n", l);
		}
	}
	return 0;
}
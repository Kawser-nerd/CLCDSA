#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
double x[200];

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		cin >> n;
		double sum = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%lf", &x[i]);
			sum += x[i];
		}	
		cout << "Case #" << it << ":";

		for (int i = 0; i < n; i++) {
			double l = 0, r = 1;
			for (int j = 0; j < 50; j++) {
				double s = (l + r) / 2;
				double h = x[i] + sum * s; 
				double tmp = s;
				for (int k = 0; k < n; k++)
					if (k != i)
						tmp += max (0.0, h - x[k]) / sum;
				if (tmp < 1) l = s; else r = s;
			}
			printf (" %.10f", (l + r) * 50);
		}
		
		cout << endl;
	}
	return 0;
}
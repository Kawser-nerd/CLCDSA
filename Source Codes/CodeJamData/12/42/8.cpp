#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int nmax = 10100;

typedef pair<double,double> point;

int px[] = {-1, -1, 1, 1};
int py[] = {-1, 1, -1, 1};

int n, w, l;
set<point> pos;
pii a[nmax];
point res[nmax];

void write(){
	forn(i, n){
		printf("%0.9lf %0.9lf", res[i].fs, res[i].sc);
		if (i + 1 < n)
			printf(" ");
		else
			puts("");
	}		
}

void add(double x, double y){
	pos.insert(mp(x, y));
}

double dist(point a, point b){
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

bool put(int i, double x, double y){
	if (x < 0 || x > w || y < 0 || y > l)
		return 0;
	res[a[i].sc] = mp(x, y);
	for (int j = 0; j < i; j ++)
		if (dist(res[a[j].sc], res[a[i].sc]) < a[j].fs + a[i].fs)
			return 0;
	return 1;
}


bool greed(){
	sort(a, a + n);
	forn(i, n / 2)
		swap(a[i], a[n - i-  1]);
	add(0, 0);
	add(w, 0);
	add(0, l);
	add(w, l);
	forn(i, n){
		bool done = 0;
		while (pos.size() > 0){
			pii now = *pos.begin();
			pos.erase(pos.begin());
			if (put(i, now.fs, now.sc)){
				done = 1;
				break;
			}
			forn(j, 4)
				if (put(i, now.fs + px[j] * a[i].fs, now.sc + py[j] * a[i].fs)){
					done = 1;
					break;
			}
			if (done) break;
		}
		if (!done) return 0;
		forn(j, 4)         
			add(res[a[i].sc].x + px[j] * a[i].fs, res[a[i].sc].y + py[j] * a[i].fs);
	}
	write();
	return 1;
}

void solve(){
	cin >> n >> w >> l;
	forn(i, n){
		cin >> a[i].fs;
		a[i].sc = i;
	}

	if (greed())
		return;
	cerr << "HUI" << endl;
}

int main ()
{
	int n;
	cin >> n;

	forn(i, n){
		printf("Case #%d: ", i + 1);
		solve();
	}

	
	return 0;
}

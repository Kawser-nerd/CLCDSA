#include <iostream>
#include <array>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <queue>
#include <iomanip>
#include <functional>
#include <climits>
#include <tuple>
#include <unordered_map>
#include <limits>
#include <functional>
#include <cassert>
#include <numeric>
#include <bitset>

#define FOR(x,n) for(int x = 0; x < n; x++)
#define INPUT(x) scanf("%d",&x)
#define PUT(x) printf("%d",x)
#define DPUT(x) printf("%.15lf\n",x)
#define GET(x,y) std::get<x>(y)
#define CHMAX(x,y) x = std::max(x,y)
#define CHMIN(x,y) x = std::min(x,y)
#define SP_END (i != n - 1 ? ' ' : '\n') ;

using namespace std;

using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = std::vector<ll>;
using vpll = std::vector<pll>;
using vpii = std::vector<pii>;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvpii = std::vector<vpii>;
using vch = std::vector<char>;
using vvch = std::vector<vch>;
using tiii = std::tuple<int, int, int>;

const ll mod197 = 1000000007LL;
const ll INF = 10000000000LL;

const double PI11 = 3.14159265359;

const int dis[5] = { 0,1,0,-1,0 };

const int disD[4] = { 0,1,1,0 };
const int disLD[3] = { 0,1,0 };

const char disC[4] = { 'U','D','R','L' };
const char disY[4] = { -1,1,0,0 };
const char disX[4] = { 0,0,1,-1 };

int a[200001] = {};
int b[200001] = {};

int main(void)
{
	int n,p;
	INPUT(n);

	for (int i = 0; i < n; i++) {
		INPUT(p);
		p--;
		a[p] += i;
		a[n + 1] -= i;
		b[0] += i;
		b[p + 1] -= i;
	}

	for (int i = 0; i < n; i++) {
		a[i + 1] += a[i];
		b[i + 1] += b[i];
		a[i] += i + 1;
		b[i] += n - i;
		PUT(a[i]);
		puts((i == n - 1 ? "\n" : " "));
	}

	for (int i = 0; i < n; i++) {
		PUT(b[i]);
		puts((i == n - 1 ? "\n" : " "));
	}

	return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;
#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("l.in", "r", stdin);
    freopen("l.out", "w", stdout);
}

struct Point
{
    int x;
    int y;
    Point(int x_, int y_): x(x_), y(y_)
    { }
};

int main()
{
    initialize();

	char str[5];
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		int n;
		cin >> n;
		int pos[2] = {1, 1};
		int c[2] = {0, 0};
		std::map<char, int> m;
		m['O'] = 0;
		m['B'] = 1;
		for (int i = 0; i < n; ++i) {
			int p;
			scanf("%s%d", str, &p);
			int ind = m[str[0]];
			int other = 1 - ind;
			c[ind] = max(c[ind] + abs(pos[ind] - p), c[other]) + 1;
			pos[ind] = p;
		}
		printf("Case #%d: %d\n", tt, max(c[0], c[1]));
	}

    return 0;
}
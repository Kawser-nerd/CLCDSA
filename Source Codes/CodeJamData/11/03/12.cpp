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

const int MAX = (int)1e6 + 10;

int main()
{
    initialize();

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		int n;
		cin >> n;
		int mm = MAX;
		int sum = 0;
		vector<int> numbers(n);
		vector<int> bits(20);
		for (int i = 0; i < n; ++i) {
			cin >> numbers[i];
			int num = numbers[i];
			mm = min(num, mm);
			sum += num;
			for (int k = 0; k < 20; ++k) {
				if ((numbers[i] & (1 << k)) > 0) {
					bits[k] += 1;
				}
			}
		}

		bool ok = true;
		for (int i = 0; i < 20; ++i) {
			if (bits[i] % 2 == 1) {
				ok = false;
			}
		}

		printf("Case #%d: ", tt);
		if (ok) {
			printf("%d", sum - mm);
		}
		else {
			printf("NO");
		}
		printf("\n");
	}

    return 0;
}
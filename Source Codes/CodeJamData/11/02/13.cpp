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

const int MAX = 256;
char r1[MAX][MAX];
char r2[MAX][MAX];

int main()
{
    initialize();

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		memset(r1, 0, sizeof(r1));
		memset(r2, 0, sizeof(r2));
		int c;
		cin >> c;
		for (int i = 0; i < c; ++i) {
			string str;
			cin >> str;
			r1[str[0] - 'A'][str[1] - 'A'] = r1[str[1] - 'A'][str[0] - 'A'] = str[2];
		}

		int d;
		cin >> d;
		for (int i = 0; i < d; ++i) {
			string str;
			cin >> str;
			r2[str[0] - 'A'][str[1] - 'A'] = r2[str[1] - 'A'][str[0] - 'A'] = 1;
		}

		int n;
		string str;
		cin >> n >> str;
		string curStr;
		for (int i = 0; i < n; ++i) {
			curStr += str[i];
			bool ok = true;
			while (ok) {
				ok = false;
				if (curStr.size() <= 1) break;
				char v = r1[curStr[curStr.size() - 1] - 'A'][curStr[curStr.size() - 2] - 'A'];
				while (curStr.size() > 1 && r1[curStr[curStr.size() - 1] - 'A'][curStr[curStr.size() - 2] - 'A'] != 0) {
					curStr.resize(curStr.size() - 2);
					curStr.push_back(v);
				}
				for (int i = 0; i + 1 < curStr.size() && !ok; ++i) {
					if (r2[curStr[i] - 'A'][curStr[curStr.size() - 1] - 'A']) {
						curStr.clear();
						ok = true;
					}
				}
			}
		}
		printf("Case #%d: [", tt);
		for (int i = 0; i < curStr.size(); ++i) {
			cout << curStr[i];
			if (i + 1 < curStr.size()) {
				cout << ", ";
			}
		}
		cout << "]\n";
	}

    return 0;
}
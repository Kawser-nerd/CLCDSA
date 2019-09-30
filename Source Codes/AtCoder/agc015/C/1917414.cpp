#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 2000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int cnt_black[3000][3000] = {};
int yoko_black[3000][3000] = {};
int tate_black[3000][3000] = {};
int grid[3000][3000] = {};
int main() {
	int n, m, query;
	cin >> n >> m >> query;
	REP(i, n) {
		string s;
		cin >> s;
		for (int q = 0;q < s.length();++q) {
			if (s[q] == '1') {
				grid[i + 1][q + 1] = 1;
			}
		}
	}
	for (int i = 1;i <= n;++i) {
		for (int q = 1;q <= m;++q) {
			cnt_black[i][q] = cnt_black[i][q - 1] + grid[i][q];
			yoko_black[i][q] = yoko_black[i][q - 1];
			tate_black[i][q] = tate_black[i][q - 1];
			if (grid[i][q] == 1 && grid[i][q-1] == 1) {
				yoko_black[i][q]++;
			}
			if (grid[i][q] == 1 && grid[i - 1][q] == 1) {
				tate_black[i][q]++;
			}
		}
	}
	for (int i = 1;i <= m;++i) {
		for (int q = 1;q <= n;++q) {
			yoko_black[q][i] += yoko_black[q - 1][i];
			tate_black[q][i] += tate_black[q - 1][i];
			cnt_black[q][i] += cnt_black[q - 1][i];
		}
	}
	REP(i, query) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ans = cnt_black[c][d] - cnt_black[a - 1][d] - cnt_black[c][b - 1] + cnt_black[a - 1][b - 1];
		ans -= yoko_black[c][d] - yoko_black[a-1][d] - yoko_black[c][b] + yoko_black[a-1][b];
		ans -= tate_black[c][d] - tate_black[a][d] - tate_black[c][b-1] + tate_black[a][b-1];
		cout << ans << endl;
	}
	return 0;
}
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int WORDS = 521196;
vector<string> dict;

const int MAXN = 4096;
const int DIST = 5;
int n;
char str[MAXN];

bool Match(int pos, int w, int &front, int &back, int &cnt) {
	const string &patt = dict[w];
	if (pos + patt.size() > n) return false;

	int last = -100;
	cnt = 0;  front = -100;
	for (int q = 0; q<patt.size(); q++)
		if (patt[q] != str[pos+q]) {
			if (last < 0) front = q;
			if (q - last < DIST) return false;
			last = q;
			cnt++;
		}
	back = patt.size()-1 - last;

	return true;
}

inline void relax(int &a, int b) {
	if (a > b) a = b;
}

int res[MAXN][8];

char buff[1<<20];
int main() {
	freopen("dict.txt", "r", stdin);
	dict.reserve(WORDS);
	for (int i = 0; i<WORDS; i++) {
		scanf("%s", buff);
		dict.push_back(buff);
	}

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%s", str);
		n = strlen(str);

		memset(res, 63, sizeof(res));

		res[0][DIST] = 0;
		for (int i = 0; i<n; i++) {
			for (int w = 0; w<WORDS; w++) {
				int first, last, cnt;
				if (!Match(i, w, first, last, cnt))
					continue;
				
				int tlen = dict[w].size();
				for (int j = 0; j<=DIST; j++) {
					if (cnt == 0)
						relax(res[i+tlen][min(j+tlen, DIST)], res[i][j]);
					else {
						if (j + first + 1 < DIST)
							continue;
						relax(res[i+tlen][min(last, DIST)], res[i][j] + cnt);
					}
				}
			}
		}

		int ans = 1000000000;
		for (int j = 0; j<=DIST; j++)
			relax(ans, res[n][j]);

		printf("Case #%d: %d\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}

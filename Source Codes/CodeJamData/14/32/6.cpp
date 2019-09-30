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
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int VERTS = 30;
const int MOD = 1000000007;

int mult(int a, int b) {
	return (int64(a) * b) % MOD;
}

int n, v;
vector<string> arr;
bool intrn[VERTS];
int nxt[VERTS], prv[VERTS], cycles[VERTS];
bool used[VERTS];

char buff[1024];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {

		scanf("%d", &n);
		arr.clear();
		for (int i = 0; i<n; i++) {
			scanf("%s", buff);
			arr.push_back(buff);
		}

		bool bad = false;
		memset(intrn, 0, sizeof(intrn));
		for (int i = 0; i<n; i++) {
			auto s = arr[i];

			if (s.front() == s.back()) {
				if (s != string(s.size(), s[0]))
					bad = true;
			}
			else {
				int left = 0;
				for (int j = 1; j < s.size(); j++) {
					if (s[j] != s[j-1]) {
						int right = j;
						int ch = s[j-1] - 'a';

						if (left > 0 && right < s.size()) {
							if (intrn[ch])
								bad = true;
							intrn[ch] = true;	
						}

						left = right;
					}
				}
			}
		}
		memset(nxt, -1, sizeof(nxt));
		memset(prv, -1, sizeof(prv));
		memset(cycles, 0, sizeof(cycles));
        for (int i = 0; i < n; i++) {
        	auto s = arr[i];
        	int f = s.front() - 'a';
        	int b = s.back() - 'a';
        	if (intrn[f] || intrn[b])
        		bad = true;

			if (f == b) cycles[f]++;
			else {
				if (nxt[f] >= 0) bad = true;
				nxt[f] = b;
				if (prv[b] >= 0) bad = true;
				prv[b] = f;
			}
        }

		v = 'z' - 'a' + 1;
		int comps = 0;
		memset(used, 0, sizeof(used));
		for (int i = 0; i < v; i++) {
			if (!cycles[i] && nxt[i] < 0 && prv[i] < 0)
				continue;
			Ef("%d =>%d <=%d    (%d)\n", i, nxt[i], prv[i], cycles[i]);
			if (prv[i] < 0) {
				comps++;
				for (int curr = i; curr >= 0; curr = nxt[curr])
					used[curr] = true;
			}
		}
		Eo(comps);
		for (int i = 0; i < v; i++) {
			if (!cycles[i] && nxt[i] < 0 && prv[i] < 0)
				continue;
			if (!used[i])
				bad = true;
		}

		int ans = 1;
		for (int j = 1; j<=comps; j++)
			ans = mult(ans, j);
		for (int i = 0; i < v; i++) {
			for (int j = 1; j<=cycles[i]; j++)
				ans = mult(ans, j);
		}

		if (bad) ans = 0;
		printf("Case #%d: %d\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}

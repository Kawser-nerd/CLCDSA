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

int random() {
	return (rand() << 15) ^ rand();
}

const int SIZE = 1024;
const int DROPS = 16;

struct Man {
	int rad;
	int name;
	inline bool operator< (const Man &b) const { return rad < b.rad; }
};

int n, w, h;
Man arr[SIZE];
int cx[SIZE], cy[SIZE];
int where[SIZE];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d%d%d", &n, &w, &h);
		for (int i = 0; i<n; i++) {
			scanf("%d", &arr[i].rad);
			arr[i].name = i;
		}

		sort(arr, arr+n);
		reverse(arr, arr+n);
			random_shuffle(arr, arr+n);

		for (int iter = 0; ; iter++) {
			fprintf(stderr, "!");
			bool bad = false;
			for (int i = 0; i<n; i++) {
			    int besty = 1001000000;
			    int bestx = -1;
				
				for (int t = 0; t<DROPS; t++) {
					int tx = random() % (w+1);
					int ty = 0;
					for (int j = 0; j<i; j++) {
						int sr = arr[i].rad + arr[j].rad;
						if (tx < cx[j] - sr || tx > cx[j] + sr)
							continue;
						ty = max(ty, cy[j] + sr);
					}
					if (besty > ty) {
						besty = ty;
						bestx = tx;
					}
				}
				
				if (besty > h) { bad = true; break; }

				cx[i] = bestx;
				cy[i] = besty;
			}

			if (!bad) break;
			random_shuffle(arr, arr+n);
		}
		fprintf(stderr, "\n");

		printf("Case #%d:", tt);
		for (int i = 0; i<n; i++) where[arr[i].name] = i;
		for (int i = 0; i<n; i++) printf(" %d %d", cx[where[i]], cy[where[i]]);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}

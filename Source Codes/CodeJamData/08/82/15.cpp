#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <iostream>
#include <queue>
#include <set>
#include <map>

#define ABS(x) ((x)<0?-(x):(x))
#define SQR(x) ((x)*(x))
#define PB push_back
#define MP make_pair
#define SS stringstream
#define LL long long
#define LD long double
#define SZ(x) int(x.size())
#define ALL(x) x.begin(),x.end()
#define FOR(a,b) for(int a=0;a<b;a++)
#define DFOR(a,b) for(int a=b-1;a>=0;a--)
#define CLR(a,b) memset(a,b,sizeof(a))
#define maxn 330
#define len 10000

using namespace std;


int n;
char buf[1000];
vector<pair<int, int> > v[maxn];
int col_cnt;
map<string, int> cols;
pair<int, int> A[maxn];
int s;

int go() {
	int left = 0;
	int cur = 0;
	int res = 0;
	while (cur < s) {
		int t = -1;
		while (cur < s && A[cur].first <= left + 1) {
			t = max(t, A[cur].second);
			cur++;
		}
		if (t <= left) {
			if (left < len) return 1000; else return res;
		}
		left = t;
		res++;
	}
	if (left < len) return 1000; else return res;
}

int get_col(string s) {
	if (cols.count(s) == 0) {
		cols[s] = col_cnt++;
	}
	return cols[s];
}

void solvecase() {
	scanf("%d", &n);
	col_cnt = 0;
	cols.clear();
	for (int i = 0; i < maxn; i++) v[i].clear();
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%s%d%d", buf, &a, &b);
		int c = get_col(string(buf));
		v[c].PB(MP(a, b));
	}
	int res = 1000;
	for (int i = 0; i < col_cnt; i++) {
		sort(ALL(v[i]));
		v[i].PB(MP(1000000, 1));
	}
	// use 1 col
	for (int i = 0; i < col_cnt; i++) {
		s = 0;
		int s1 = SZ(v[i]) - 1;
		for (int q = 0; q < s1; q++)
			A[s++] = v[i][q];
		res = min(res, go());
	}
	// use 2 cols
	for (int i = 0; i < col_cnt; i++)
		for (int j = i+1; j < col_cnt; j++) {
			s = 0;
			int s1 = SZ(v[i]) - 1;
			int s2 = SZ(v[j]) - 1;
			int q1 = 0;
			int q2 = 0;
			while (q1 < s1 || q2 < s2) {
				if (v[i][q1].first <= v[j][q2].first)
					A[s++] = v[i][q1++];
				else
					A[s++] = v[j][q2++];
			}
			res = min(res, go());
		}
	// use 3 cols
	for (int i = 0; i < col_cnt; i++)
		for (int j = i+1; j < col_cnt; j++)
			for (int k = j+1; k < col_cnt; k++) {
				s = 0;
				int s1 = SZ(v[i]) - 1;
				int s2 = SZ(v[j]) - 1;
				int s3 = SZ(v[k]) - 1;
				int q1 = 0;
				int q2 = 0;
				int q3 = 0;
				while (q1 < s1 || q2 < s2 || q3 < s3) {
					if (v[i][q1].first <= v[j][q2].first && v[i][q1].first <= v[k][q3].first)
						A[s++] = v[i][q1++];
					else if (v[j][q2].first <= v[i][q1].first && v[j][q2].first <= v[k][q3].first)
						A[s++] = v[j][q2++];
					else
						A[s++] = v[k][q3++];

				}
				res = min(res, go());
			}	
	if (res == 1000) {
		printf("IMPOSSIBLE");
	} else {
		printf("%d", res);
	}	
}

void solve() {
	int n;
	scanf("%d\n", &n);
	FOR(i, n) {
		printf("Case #%d: ", i+1);
		solvecase();
		printf("\n");
	}
}

int main() {
	freopen("y", "rt", stdin);
	//freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	solve();
	return 0;
}
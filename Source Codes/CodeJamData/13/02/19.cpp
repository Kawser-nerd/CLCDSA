#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MP make_pair
#define PB push_back
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAX_N = 100 + 10;
int N, M;
int a[MAX_N][MAX_N];
int col[MAX_N], row[MAX_N];

void solve(int test)
{
	printf("Case #%d: ", test);
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++ i) row[i] = 0;
	for(int i = 0; i < M; ++ i) col[i] = 0;
	
	for(int i = 0; i < N; ++ i) 
		for(int j = 0; j < M; ++ j) {
			scanf("%d", &a[i][j]);
			row[i] = max(row[i], a[i][j]);
			col[j] = max(col[j], a[i][j]);
		}
		
	for(int i = 0; i < N; ++ i)
		for(int j = 0; j < M; ++ j)
			if (a[i][j] != min(row[i], col[j])) {
				puts("NO");
				return;
			}
	puts("YES");
}

int main()
{
	//freopen("B.in", "r", stdin); freopen("B.out", "w", stdout);
	//freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	int testcase; scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) solve(i);
	fclose(stdout);
	return 0;
}

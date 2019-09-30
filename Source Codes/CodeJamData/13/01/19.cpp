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

char a[5][5];
char b[5];

int check(char a0, char a1, char a2, char a3)
{
	int O = false, X = false;
	b[0] = a0; b[1] = a1; b[2] = a2; b[3] = a3;
	for(int i = 0; i < 4; ++ i) {
		if (b[i] == '.') return false;
		if (b[i] == 'X') X = true;
		if (b[i] == 'O') O = true;
	}
	if (X && O) return false;
	printf("%c won\n", X ? 'X' : 'O');
	return true;
}

void solve(int test)
{
	printf("Case #%d: ", test);
	int cnt = 0;
	for(int i = 0; i < 4; ++ i) {
		scanf("%s", a[i]);
		for(int j = 0; j < 4; ++ j)
			cnt += (a[i][j] == '.');
	}
	for(int i = 0; i < 4; ++ i) {
		if (check(a[i][0], a[i][1], a[i][2], a[i][3])) return;
		if (check(a[0][i], a[1][i], a[2][i], a[3][i])) return;
	}
	if (check(a[0][0], a[1][1], a[2][2], a[3][3])) return;
	if (check(a[0][3], a[1][2], a[2][1], a[3][0])) return;
	if (cnt) puts("Game has not completed");
	else puts("Draw");
}

int main()
{
	//freopen("A.in", "r", stdin); freopen("A.out", "w", stdout);
	//freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	int testcase; scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) solve(i);
	fclose(stdout);
	return 0;
}

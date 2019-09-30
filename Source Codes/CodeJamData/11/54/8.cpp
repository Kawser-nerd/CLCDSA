#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

char s[150];

LL val[150];

int pos[45];
int cPos;

int n;

LL sum;

void alg() {
	scanf("%s", s);
	n = 0;
	while (s[n])
		++n;
	sum = 0;
	cPos = 0;
	for (int i = 0; i < n; ++i)
		if (s[i] == '?')
			pos[cPos++] = i;
		else if (s[i] == '1')
			sum += (1LL << (n - i - 1));
	for (int mask = 0; mask < (1 << cPos); ++mask) {
		LL csum = sum;
		for (int j = 0; j < cPos; ++j)
			if ((mask >> j) & 1)
				csum += (1LL << (n - pos[j] - 1));
		LL a = sqrtl(csum);
		while (a * a > csum)
			--a;
		while (a * a < csum)
			++a;
		if (a * a == csum) {
			for (int j = 0; j < cPos; ++j) {
				s[pos[j]] = ((mask >> j) & 1) + '0';
			}
			printf("%s\n", s);
			return;
		}
	}
}

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		printf("Case #%d: ", testCase);
		alg();
	}
}

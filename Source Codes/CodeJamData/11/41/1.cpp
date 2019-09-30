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
typedef long double LD;
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

void alg() {
	int length, n, runningSpeed, walkingSpeed;
	LD runningTime;
	scanf("%d %d %d %Lf %d", &length, &walkingSpeed, &runningSpeed, &runningTime, &n);
	runningSpeed -= walkingSpeed;
	vector<PII> walkways(n);
	for (int i = 0; i < n; ++i) {
		int start, end;
		scanf("%d %d %d", &start, &end, &walkways[i].ST);
		walkways[i].ST += walkingSpeed;
		walkways[i].ND = end - start;
		length -= walkways[i].ND;
	}
	walkways.PB(MP(walkingSpeed, length));
	sort(ALL(walkways));
	++n;
	LD result = 0;
	for (int i = 0; i < n; ++i) {
		LD running = min(runningTime, walkways[i].ND / LD(walkways[i].ST + runningSpeed));
		runningTime -= running;
		result += running;
		result += (walkways[i].ND - running * (walkways[i].ST + runningSpeed)) / LD(walkways[i].ST);
	}
	printf("%.10Lf\n", result);
}

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		printf("Case #%d: ", testCase);
		alg();
	}
}

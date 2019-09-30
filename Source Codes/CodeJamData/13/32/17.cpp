#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define SIZE(v) ((int)(v).size())

#define BEGIN(v) ((v).begin())
#define END(v) ((v).end())
#define ALL(v) BEGIN(v),END(v)
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v);(v).erase(unique(ALL(v)),END(v))

#define FOR(i,l,r) for(int i=(l);i<(r);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)

int main() {
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 1; taskIdx <= taskNumber; taskIdx++) {
		int x, y; scanf("%d%d", &x, &y);
		printf("Case #%d: ", taskIdx);
		FOR(i, 0, abs(x)) {
			if (x < 0) printf("EW");
			else printf("WE");
		}
		FOR(i, 0, abs(y)) {
			if (y < 0) printf("NS");
			else printf("SN");
		}
		putchar('\n');
	}
	return 0;
}

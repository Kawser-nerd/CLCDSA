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

const int MAXL = 1000001;

int n, m, longest[MAXL];
char s[MAXL];
bool consonant[MAXL];

int main() {
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 1; taskIdx <= taskNumber; taskIdx++) {
		scanf("%s%d", s, &m);
		n = strlen(s);
		FOR(i, 0, n) {
			consonant[i] = s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u';
		}
		longest[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			longest[i] = consonant[i] ? longest[i + 1] + 1 : 0;
		}
		int prevPosition = -1;
		long long res = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (longest[i] >= m) prevPosition = i + m;
			if (prevPosition != -1) {
				res += n - prevPosition + 1;
			}
		}
		printf("Case #%d: %lld\n", taskIdx, res);
	}
	return 0;
}

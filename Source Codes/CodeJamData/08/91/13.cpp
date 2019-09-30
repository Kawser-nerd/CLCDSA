#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
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

const int MAXN = 5000;
const int TOTAL = 10000;

class Person {
public:
	int a, b, c;
};

Person persons[MAXN];
int changes[TOTAL + 100];

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &persons[i].a, &persons[i].b, &persons[i].c);
		}
		int ans = 0;
		for (int a = 0; a <= TOTAL; a++) {
			memset(changes, 0, sizeof(changes));
			for (int i = 0; i < n; i++) {
				if (persons[i].a <= a && persons[i].b + persons[i].c <= TOTAL - a) {
					changes[persons[i].b]++;
					changes[TOTAL - a - persons[i].c + 1]--;
				}
			}
			int cur = 0;
			for (int b = 0; b <= TOTAL - a; b++) {
				cur += changes[b];
				ans = max(ans, cur);
				//if (caseIndex == 2 && cur == 3) {
				//	printf("%d %d\n", a, b);
				//}
			}
		}
		printf("Case #%d: %d\n", caseIndex, ans);
	}

	return 0;
}

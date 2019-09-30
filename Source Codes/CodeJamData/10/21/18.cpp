#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

char s[200];

int main() {
	int T; scanf("%d", &T);
	for (int tt = 0; tt < T; ++tt) {
		int n, m; scanf("%d %d", &n, &m);
		set<string> e;
		e.insert("/");
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			e.insert(s);
		}
		int result = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%s", s);
			string ss = s;
			for (int j = 1; ss[j] != 0; ++j) {
				if (ss[j] == '/') {
					string t = ss.substr(0, j);
					if (e.find(t) == e.end()) {
						e.insert(t);
						++result;
					}
				}
			}
			if (e.find(s) == e.end()) {
				e.insert(s);
				++result;
			}
		}
		printf("Case #%d: %d\n", tt + 1, result);
	}
	return 0;
}

#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int ans, l;
char S[1000];
int T;
int C;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", S + 1);
		l = strlen(S + 1);
		S[l + 1] = '+';
		printf("Case #%d: ", ++C);
		int ans = 0;
		for (int i = 1; i <= l; i++)
			if (S[i] != S[i + 1])
				ans += 1;
		
		ans = max(ans, 0);
		printf("%d\n", ans);
	}
}

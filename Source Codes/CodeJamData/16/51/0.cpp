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

char S[1100000];
int zhan[1100000];

void doit() {
	scanf("%s", S + 1);
	int n = strlen(S + 1);
	int tot = 0;
	int q = 1, h = 0;
	for (int i = 1; i <= n; i++) {
		// if (i < n && S[i] == S[i + 1])
		// 	tot += 1, i += 1;
		if (h && S[i] == S[zhan[h]])
			tot += 1, h--;
		else
			zhan[++h] = i;
	}
	// printf("%d\n", tot);
	printf("%d\n", tot * 10 + (n / 2 - tot) * 5);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: " , i);
		doit();
	}
}

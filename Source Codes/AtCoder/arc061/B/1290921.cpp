#include <stdio.h>
#include <string.h>
#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_set>
#include<unordered_map>
#define P pair<int,int>
#define int long long 
using namespace std;

int ans[10];
signed main() {
	int a, b, c; cin >> a >> b >> c;
	ans[0] += (a - 2)*(b - 2);
	unordered_map<int, unordered_map<int, bool>>U;
	for (int d = 0; d < c; d++) {
		int e, f; scanf("%lld%lld", &e, &f); e--; f--;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				int sum = 0;
				int n = e + i, m = f + j;
				for (int x = -1; x < 2; x++) {
					for (int y = -1; y < 2; y++) {
						if (n + x < 0 || n + x >= a || m + y < 0 || m + y >= b)goto l;
						if (U[n + x][ m + y])sum++;
					}
				}
				ans[sum]--;
				ans[sum + 1]++;
			l:;
			}
		}
		U[e][f] = true;
	}
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << endl;
	}
}
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<limits.h>
#include<string>
using namespace std;

int rui[500][501];
signed main() {
	int a, b, c; cin >> a >> b >> c;
	int ans = 0;
	for (int i = 0; i < a; i++) {
		string d; cin >> d;
		int e = 0;
		for (int f = 0; f < b; f++) {
			if (d[f] == 'x')e++;
			rui[i][f + 1] = e;
		}
	}
	for (int i = c - 1; i <= a - c; i++) {
		for (int j = c - 1; j <= b - c; j++) {
			bool OK = true;
			for (int k = i - (c - 1); k < i + c; k++) {
				if (rui[k][j + c - abs(i - k)] - rui[k][j - c + abs(i - k) + 1]) { OK = false; break; }
			}
			if (OK)ans++;
		}
	}
	cout << ans << endl;
}
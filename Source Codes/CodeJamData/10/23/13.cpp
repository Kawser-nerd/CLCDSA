#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template<class T> int size(const T & a) {
	return (int)a.size();
}
template<class T> T sqr(const T &a) {
	return a * a;
}

int cmn[501][501];
int dm[500][500];
const int base = 100003;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int ntests;
	scanf("%d", &ntests);
	for (int i = 0; i <= 500; i++) {
		cmn[0][i] = 1;
	}
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			cmn[i][j] = (cmn[i - 1][j - 1] + cmn[i][j - 1]) % base;
		}
	}
	for (int i = 2; i <= 500; i++) {
		dm[i][1] = 1;
	}
	for (int i = 2; i <= 500; i++) {
		for (int j = 2; j < i; j++) {
			for (int k = 1; k < j; k++) {
				dm[i][j] = (dm[i][j] + (long long)dm[j][k] * cmn[j - k - 1][i - j - 1]) % base;
			}
		}
	}
	for (int itest = 1; itest <= ntests; itest++) {
		printf("Case #%d: ", itest);
		int n;
		scanf("%d", &n);
		int res = 0;
		for (int i = 1; i < n; i++) {
			res = (res + dm[n][i]) % base;
		}
		cout << res << endl;
	}
	return 0;
}
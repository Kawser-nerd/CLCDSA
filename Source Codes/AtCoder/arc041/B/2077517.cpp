// B. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int a[512][512] = {}, b[512][512];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			b[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			a[i + 1][j] = b[i][j];
			b[i + 1][j - 1] -= b[i][j];
			b[i + 1][j + 1] -= b[i][j];
			b[i + 2][j] -= b[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << (char)('0' + a[i][j]);
		}
		cout << endl;
	}
	return 0;
}
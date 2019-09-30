#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <cstdio>
#include <cmath>
using namespace std;

string a[50], b[50];
int n, m;

bool match(int x,int y) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (a[x + i][y + j] != b[i][j]) return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	bool judge = false;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			if (match(i,j))judge = true;
		}
	}
	if (judge)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;

}
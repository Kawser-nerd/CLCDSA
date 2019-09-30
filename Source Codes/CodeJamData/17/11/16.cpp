#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const int INF = (int)(1e9);

const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0, 0,1,-1 };


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
		cerr << "Case #" << test << ": ";
		
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		for (int k = 0; k < 4; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (a[i][j] != '?') {
						int x = i + dx[k];
						int y = j + dy[k];
						while (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '?') {
							a[x][y] = a[i][j];
							x += dx[k];
							y += dy[k];
						}
					}
				}
			}
		}


		cout << endl;
		cerr << endl;
		for (int i = 0; i < n; i++) {
			cout << a[i] << endl;
			//cerr << a[i] << endl;
		}
	}

	return 0;
}
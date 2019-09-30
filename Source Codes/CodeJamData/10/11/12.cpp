#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>

#define INF 1000000000
#define EPS 1E-8
#define PI 3.14159265358979

using namespace std;

char state[60][60];
int dx[4] = {0, 1, 1, -1}, dy[4] = {1, 0, 1, 1};

pair<bool, bool> win(int n, int k) {
	bool red = false, blue = false;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) if(state[i][j] != '.') {
			for(int d = 0; d < 4; ++d) {
				int num = 0;
				int x = i, y = j;
				for(int l = 0; l < k; ++l) {
					if(x < 0 || x >= n || y < 0 || y >= n || state[x][y] != state[i][j]) break;
					++num;
					x += dx[d]; y += dy[d];
				}
				if(num >= k) {
					if(state[i][j] == 'R') red = true;
					if(state[i][j] == 'B') blue = true;
				}
			}
		}
	}
	return make_pair(red, blue);
}

void rotate(int n) {
	char next[60][60];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			next[j][n - 1 - i] = state[i][j];
			state[i][j] = '.';
		}
	}
	for(int i = 0; i < n; ++i) {
		int y = n - 1;
		for(int j = n - 1; j >= 0; --j) if(next[j][i] != '.') {
			state[y--][i] = next[j][i];
		}
	}
}

int main() {
	int N;
	cin >> N;
	for(int t = 0; t < N; ++t) {
		printf("Case #%d: ", t + 1);
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < n; ++i) scanf("%s", state[i]);
		rotate(n);
		/*for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) cerr << state[i][j];
			cerr << endl;
		}*/
		pair<bool, bool> w = win(n, k);
		if(w.first && w.second) puts("Both");
		else if(w.first) puts("Red");
		else if(w.second) puts("Blue");
		else puts("Neither");
	}
	return 0;
}

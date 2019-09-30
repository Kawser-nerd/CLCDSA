#include<bits/stdc++.h>
using namespace std;

const int MAXR = 200;
const int MAXC = 200;

int R, C;
char grid[MAXR][MAXC];

bool isGood[MAXR][MAXC];
bool hasGood[MAXR][MAXC];

int go() {

	memset(isGood, 0, sizeof(isGood));
	memset(hasGood, 0, sizeof(hasGood));
	bool good;
	for(int i = 0; i < R; i++) {
		good = false;
		for(int j = 0; j < C; j++) {
			if(grid[i][j] == '.') continue;
			else if(good) {
				hasGood[i][j] = true;
				if(grid[i][j] == '<') isGood[i][j] = true;
			} else {
				good = true;
			}
		}

		good = false;
		for(int j = C - 1; j >= 0; j--) {
			if(grid[i][j] == '.') continue;
			else if(good) {
				hasGood[i][j] = true;
				if(grid[i][j] == '>') isGood[i][j] = true;
			} else {
				good = true;
			}
		}
	}

	for(int j = 0; j < C; j++) {
		good = false;
		for(int i = 0; i < R; i++) {
			if(grid[i][j] == '.') continue;
			else if(good) {
				hasGood[i][j] = true;
				if(grid[i][j] == '^') isGood[i][j] = true;
			} else {
				good = true;
			}
		}

		good = false;
		for(int i = R - 1; i >= 0; i--) {
			if(grid[i][j] == '.') continue;
			else if(good) {
				hasGood[i][j] = true;
				if(grid[i][j] == 'v') isGood[i][j] = true;
			} else {
				good = true;
			}
		}
	}

	int res = 0;
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			if(grid[i][j] == '.') continue;
			else if(!hasGood[i][j]) {
				return -1;
			} else if(!isGood[i][j]) {
				res++;
			}
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> R >> C;
		for(int r = 0; r < R; r++) {
			cin >> grid[r];
		}
		int res = go();
		cout << "Case #" << t << ": ";
		if(res == -1) cout << "IMPOSSIBLE\n";
		else cout << res << '\n';
	}
	return 0;
}

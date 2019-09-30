#include<iostream>
#include<cstring>

using namespace std;

int R, C, M;
bool res[100][100];

bool solve() {
	memset(res, false, sizeof(res));

	int O = R * C - M;

	if(O == 1) {
		return true; 
	} else if(R == 1) {
		for(int i = 0; i < O; i++) res[0][i] = true;
		return true;
	} else if (C == 1) {
		for(int i = 0; i < O; i++) res[i][0] = true;
		return true;
	} else if(O < 4 || O == 5 || O == 7) {
		return false;
	} else if(R == 2) {
		if(O % 2 != 0) return false;
		for(int i = 0; i < O / 2; i++) res[0][i] = res[1][i] = true;
		return true;
	} else if(C == 2) {
		if(O % 2 != 0) return false;
		for(int i = 0; i < O / 2; i++) res[i][0] = res[i][1] = true; 
		return true;
	} else if (O == 4) {
		res[0][0] = res[0][1] = res[1][0] = res[1][1] = true;
	} else {
		//O >= 6, R >= 3, C >= 3

		if(O <= C * 3) {
			// fill by col
			// at least 2 columns
			if(O % 3 == 0) {
				for(int c = 0; c < O / 3; c++) {
					res[0][c] = res[1][c] = res[2][c] = true;
				}
			} else if(O % 3 == 1) {
				for(int c = 0; c < (O - 4) / 3; c++) {
					res[0][c] = res[1][c] = res[2][c] = true;
				}
				res[0][O/3 - 1] = res[1][O/3 - 1] = res[0][O/3] = res[1][O/3] = true;
			} else {
				for(int c = 0; c < O / 3; c++) {
					res[0][c] = res[1][c] = res[2][c] = true;
				}
				res[0][O/3] = res[1][O/3] = true;
			}
		} else {
			// fill by row
			// O >= 9
			for(int r = 0; r < O / C; r++) {
				for(int c = 0; c < C; c++) {
					res[r][c] = true;
				}
			}

			for(int c = 0; c < O % C; c++) {
				res[O / C][c] = true;
			}

			if(O % C == 1) {
				res[O / C][1] = true;
				res[O / C - 1][C - 1] = false;
			}
		}

		return true;
	}
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> R >> C >> M;

		bool good = solve();

		cout << "Case #" << t << ':' << '\n';
		if(good) {
			for(int i = 0; i < R; i++) {
				for(int j = 0; j < C; j++) {
					cout << ((i == 0 && j == 0) ? ('c') : (res[i][j] ? '.' : '*'));
				}
				cout << '\n';
			}
		} else {
			cout << "Impossible" << '\n';
		}
	}
	return 0;
}

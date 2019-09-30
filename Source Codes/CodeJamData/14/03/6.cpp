#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

vector<string> ff(int R, int C, int M) {
	if (R > C) {
		vector<string> T = ff(C, R, M); 
		if (T.empty()) return T; 
		vector<string> S(R); 
		for (int i = 0; i < C; i ++)
			for (int j = 0; j < R; j ++) 
				S[j] += T[i][j]; 
		return S; 
	}
	if (R*C-M == 1) {
		vector<string> S(R); 
		for (int i = 0; i < R; i ++) 
			for (int j = 0; j < C; j ++) 
				if (i == 0 && j == 0) S[i] += 'c'; 
				else S[i] += '*'; 
		return S; 
	}
	if (R == 1) {
		vector<string> S(R); 
		for (int i = 0; i < R; i ++) 
			for (int j = 0; j < C; j ++) 
				if (i == 0 && j == 0) S[i] += 'c'; else
				if (i == 0 && j < R*C-M) S[i] += '.'; 
				else S[i] += '*'; 
		return S; 
	} else
	if (R == 2) {
		if ((R*C-M)%2 == 0 && (R*C-M) >= 4) {
			vector<string> S(R); 
			for (int i = 0; i< R; i ++) 
				for (int j = 0; j < C; j ++) 
					if (i == 0 && j == 0) S[i] += 'c'; else
					if (j < (R*C-M)/2) S[i] += '.'; 
					else S[i] += '*'; 
			return S; 
		} else return vector<string>(); 
	} else {
		if ((R*C-M) == 4) {
			vector<string> S(R); 
			for (int i = 0; i< R; i ++) 
				for (int j = 0; j < C; j ++) 
					if (i == 0 && j == 0) S[i] += 'c'; else
					if (i < 2 && j < 2) S[i] += '.'; 
					else S[i] += '*'; 
			return S; 
		} else
		if ((R*C-M) == 6) {
			vector<string> S(R); 
			for (int i = 0; i< R; i ++) 
				for (int j = 0; j < C; j ++) 
					if (i == 0 && j == 0) S[i] += 'c'; else
					if (i < 2 && j < 3) S[i] += '.'; 
					else S[i] += '*'; 
			return S; 
		} else
		if ((R*C-M) == 8) {
			vector<string> S(R); 
			for (int i = 0; i< R; i ++) 
				for (int j = 0; j < C; j ++) 
					if (i == 0 && j == 0) S[i] += 'c'; else
					if (i < 2 && j < 3 || i < 3 && j < 2) S[i] += '.'; 
					else S[i] += '*'; 
			return S; 
		} else
		if ((R*C-M) >= 8) {
			int z = R*C-M; 
			if (z/R >= 2 && z%R != 1) {
				int w = 0; 
				vector<string> S(R); 
				for (int j = 0; j < C; j ++) 
					for (int i = 0; i< R; i ++) 
						if (i == 0 && j == 0) {S[i] += 'c'; w ++; } else
						if (w < z) {S[i] += '.'; w ++;}
						else S[i] += '*'; 
				return S; 
			}
			if (z/C >= 2 && z%C != 1) {
				int w = 0; 
				vector<string> S(R); 
				for (int i = 0; i< R; i ++) 
					for (int j = 0; j < C; j ++) 
						if (i == 0 && j == 0) {S[i] += 'c'; w ++; } else
						if (w < z) {S[i] += '.'; w ++;}
						else S[i] += '*'; 
				return S; 
			}
			if (z/R >= 3) {
				int w = 0; 
				vector<string> S(R); 
				for (int j = 0; j < C; j ++) 
					for (int i = 0; i< R; i ++) 
						if (i == 0 && j == 0) {S[i] += 'c'; w ++; } else
						if (w <= z) {S[i] += '.'; w ++;}
						else S[i] += '*'; 
				S[R-1][z/R-1] = '*'; 
				return S; 
			}
			for (int x = 2; x <= R-1; x ++) 
				for (int y = 2; y <= C-1; y ++) 
					if (x*y <= z && z-x*y < x && z-x*y < y && z%y != 1) {
						int w = 0; 
						vector<string> S(R); 
						for (int i = 0; i< R; i ++) 
							for (int j = 0; j < C; j ++) 
								if (i == 0 && j == 0) {S[i] += 'c'; w ++; } else
								if (i <= x && j < y && w < z) {S[i] += '.'; w ++;}
								else S[i] += '*'; 
						return S; 
					}
			for (int x = 2; x <= R-1; x ++) 
				for (int y = 2; y <= C-1; y ++) 
					if (x*y <= z && z-x*y < x && z-x*y < y && z%x != 1) {
						int w = 0; 
						vector<string> S(R); 
						for (int j = 0; j < C; j ++) 
							for (int i = 0; i< R; i ++) 
								if (i == 0 && j == 0) {S[i] += 'c'; w ++; } else
								if (i < x && j <= y && w < z) {S[i] += '.'; w ++;}
								else S[i] += '*'; 
						return S; 
					}
			for (int x = 3; x <= R-1; x ++) 
				for (int y = 3; y <= C-1; y ++) 
					if (x*y <= z && z-x*y < x && z-x*y < y) {
						int w = 0; 
						vector<string> S(R); 
						for (int i = 0; i< R; i ++) 
							for (int j = 0; j < C; j ++) 
								if (i == 0 && j == 0) {S[i] += 'c'; w ++; } else
								if (i <= x && j < y && w <= z) {S[i] += '.'; w ++;}
								else S[i] += '*'; 
						S[z/y-1][y-1] = '*'; 
						return S; 
					}
		} else return vector<string>(); 
	}
}

int main() {
	int _; cin >> _; 
	for (int __ = 1; __ <= _; __ ++) {
		int R, C, M; 
		cin >> R >> C >> M; 
		vector<string> S = ff(R, C, M); 
		printf ("Case #%d:\n", __); 
		//*
		if (S.empty()) puts ("Impossible"); else {
			for (int i = 0; i < R; i ++) 
				printf ("%s\n", S[i].c_str()); 
		}
		//*/
		/*
		if (!S.empty()) {
			bool F = 0; 
			if ((int) S.size() != R) {puts("ERROR"); return 0; }
			for (int i = 0; i < R; i ++) 
				if (S[i].length () != C) {puts ("ERROR"); return 0;}
			int z = 0; 
			for (int i = 0; i < R; i ++) {
				for (int j = 0; j < C; j ++) {
					if (S[i][j] == 'c')
						if (F) {puts ("E2"); return 0; }
						else F = 1; 
					if (S[i][j] == '*') z ++; 
				}
			}
			if (!F) {puts ("E3"); return 0; }
			if (z != M) {puts ("E4"); return 0; }
		}
		*/
	}
	return 0; 
}
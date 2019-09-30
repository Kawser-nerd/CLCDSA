#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int,int>

ofstream fout ("QC.out");
ifstream fin ("QC.in");

int R,C,M;
int output[55][55];

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		fin >> R >> C >> M;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) output[i][j] = 0;
		}
		output[0][0] = 2;
		bool possible = true;
		if (R == 1 && C == 1) {
			//exception case 1: do nothing
		}
		else if (R == 1) {
			//always possible: situate click on one end, mines starting from the other
			for (int i = C-1; i >= C-M; i--) output[0][i] = 1;
			for (int i = C-M-1; i > 0; i--) output[0][i] = 0;
		}
		else if (C == 1) {
			//refer to above
			for (int i = R-1; i >= R-M; i--) output[i][0] = 1;
			for (int i = R-M-1; i > 0; i--) output[i][0] = 0;
		}
		else {
			//R >= 2 && C >= 2
			//As long as we have >= 4 spaces, it is possibly possible. Alternatively, if we have 1 space, it is also possible
			//Other illegal amount of empty spaces include: 5,7
			int open = R*C-M;
			if ((open < 4 && open > 1) || open == 5 || open == 7) possible = false;
			else if (open == 1) {
				//just the clicked square
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) output[i][j] = 1;
				}
				output[0][0] = 2;
			}
			else if (C != 2 && R != 2) {
				//First fill up rows not including the first 2 rows. Go from right to left.
				int rind = R-1;
				while (M > 0 && rind > 1) {
					int ntf = min(M,C);
					for (int i = C-1; i >= C-ntf; i--) output[rind][i] = 1;
					if (M == C-1) {
						output[rind][1] = 0;
						output[rind-1][C-1] = 1;
						if (rind == 2) {
							output[rind][2] = 0;
							output[rind-2][C-1] = 1;
						}
					}
					M-=ntf;
					rind--;
				}
				if (M > 0) {
					//Now to kill up the first 2 rows.
					if (open%2 == 1) {
						//move three things up.
						open -= 3;
						output[2][0] = 0;
						output[2][1] = 0;
						output[2][2] = 0;
					}
					//If there are an even number of spaces, we can just make a rectangle.
					if (open%2 == 0) {
						for (int i = 0; i < open/2; i++) {
							output[0][i] = 0;
							output[1][i] = 0;
						}
						for (int i = open/2; i < C; i++) {
							output[0][i] = 1;
							output[1][i] = 1;
						}
						output[0][0] = 2;
					}
				}
			}
			else {
				if (open%2 != 0) {
					possible = false;
				}
				else {
					for (int i = 0; i < open/2; i++) {
						if (R == 2) {
							output[0][i] = 0;
							output[1][i] = 0;
						}
						else {
							output[i][0] = 0;
							output[i][1] = 0;
						}
					}
					for (int i = open/2; i < max(R,C); i++) {
						if (R == 2) {
							output[0][i] = 1;
							output[1][i] = 1;
						}
						else {
							output[i][0] = 1;
							output[i][1] = 1;
						}
					}
					output[0][0] = 2;
				}
			}
		}
		fout << "Case #" << t << ": " << endl;
		if (!possible) fout << "Impossible" << endl;
		else {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (output[i][j] == 2) fout << "c";
					else if (output[i][j] == 1) fout << "*";
					else fout << ".";
				}
				fout << endl;
			}
		}
	}
    return 0;
}
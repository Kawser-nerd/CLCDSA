#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <map>
#include <string>
#include <set>

using namespace std;

int dat[100][8];
int rorder[100][8];

int N, M;
bool chk[8];

int integ[8];
int sol = 0;
void back(int a) {
	if (a == M) {
		vector<vector<int> > Sdata;
		for (int i = 0; i < N; i++) {
			vector<int> row;
			for (int j = 0; j < M; j++) {
				row.push_back(rorder[i][j]);
			}
			Sdata.push_back(row);
		}

		for (int j = 0; j < M; j++) integ[j] = 0;

		for (int m = 0; m < M; m++) {
			vector< vector<int> > nextData;
			for (int i = 0; i < Sdata.size(); i++) {
				int eval = 0;
				for (int j = m; j < M; j++) {
					eval += Sdata[i][j];
				}
				if (eval < 0 && Sdata[i][m] < 0) {
					for (int j = 0; j < M; j++) {
						integ[j] += Sdata[i][j];
						if (integ[j] < 0) integ[j] = 0;
					}
				}
				else {
					nextData.push_back(Sdata[i]);
				}
			}
			Sdata = nextData;
		}

		for (int i = 0; i < Sdata.size(); i++) {
			for (int j = 0; j < M; j++) {
				integ[j] += Sdata[i][j];
				if (integ[j] < 0) integ[j] = 0;
			}
		}

		int res = 0;
		for (int j = 0; j < M; j++) res += integ[j];
		if (res > sol) sol = res;
	}
	for (int i = 0; i < M; i++) {
		if (!chk[i]) {
			chk[i] = true;
			for (int j = 0; j < N; j++) rorder[j][a] = dat[j][i];
			back(a + 1);
			chk[i] = false;
		}
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
		freopen("E-small-attempt1.in", "r", stdin);
		freopen("E-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) scanf("%d", &dat[i][j]);
		}
		sol = 0;
		memset(chk, 0, sizeof(chk));
		back(0);

		printf("Case #%d: %d\n", cs, sol);
	}
	return 0;
}
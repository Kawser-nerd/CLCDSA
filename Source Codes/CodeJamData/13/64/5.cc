#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int d[100001][4];

main() {
	int T, prob=1;
	for (cin >> T; T--;) {
		int N, D, K;
		cin >> N >> D >> K;
		memset(d, 0, sizeof(d));
		for (int i = 0; i < N; i++)
		for (int j = 0; j < D; j++)
			cin >> d[i][j];
		int ret = 0, reta = -1, retb = -1;
		for (int i = 0; N-i > ret; i++)
		for (int d1 = 0; d1 < D; d1++) {
			int k1 = d[i][d1], j;
			for (j = i+1; j < N; j++) {
				if (d[j][0] == k1 || d[j][1] == k1 || d[j][2] == k1 || d[j][3] == k1)
					continue;
				break;
			}
			if (j < N) for (int d2 = 0; d2 < D; d2++) {
				int k2 = d[j][d2], k;
				for (k = j+1; k < N; k++) {
					if (d[k][0] == k1 || d[k][1] == k1 || d[k][2] == k1 || d[k][3] == k1)
						continue;
					if (d[k][0] == k2 || d[k][1] == k2 || d[k][2] == k2 || d[k][3] == k2)
						continue;
					break;
				}
				if (k-i > ret) {ret = k-i; reta = i; retb = k-1;}
			}
			if (j-i > ret) {ret = j-i; reta = i; retb = j-1;}
		}
		cout << "Case #" << prob++ << ": " << reta << ' ' << retb << endl;
	}
}

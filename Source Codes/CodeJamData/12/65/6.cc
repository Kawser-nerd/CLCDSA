#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
int path[41][2], poss[41], seen[41];
int memo_node[21][1<<20], memo_b[21][1<<20], memo_n[21][1<<20];

bool rec(int n) {
	if (n == N) return true;
	if (seen[n]) return false;
	seen[n] = true;
	return rec(path[n][0]) || rec(path[n][1]);
}

main() {
	int T, prob = 1;
	for (cin >> T; T--;) {
		cin >> N;
		for (int i = 1; i <= N-1; i++) cin >> path[i][0] >> path[i][1];

		for (int i = 1; i <= N; i++) {
			memset(seen, 0, sizeof(seen));
			poss[i] = rec(i);
		}
		rec(0);

		memset(memo_node, -1, sizeof(memo_node));
		int n = 1;
		long long b = 0;
		long long ret = 0;
		for(;;) {
			if (!poss[n]) {ret = 1e18; break;}
			if (n == N) break;
			if (n < 0) {
				int mb = (b>>1)&((1<<(N/2))-1);
				if (memo_node[n][mb] == -1) {
					vector<int> vn, vmb;
					int cn = n, cmb = mb;
					do {
						vn.push_back(cn);
						vmb.push_back(cmb);
						int n2 = path[cn][(cmb>>(cn-1))&1];
						cmb ^= (1<<(cn-1));
						cn = n2;
					} while (poss[cn] && cn < N/2 && memo_node[cn][cmb] == -1);
					if (poss[cn] && cn < N/2) {
						for (int i = 0; i < vn.size(); i++) {
							memo_n[vn[i]][vmb[i]] = vn.size() + memo_n[cn][cmb];
							memo_node[vn[i]][vmb[i]] = memo_node[cn][cmb];
							memo_b[vn[i]][vmb[i]] = memo_b[cn][cmb];
						}
					} else {
						for (int i = 0; i < vn.size(); i++) {
							memo_n[vn[i]][vmb[i]] = vn.size();
							memo_node[vn[i]][vmb[i]] = cn;
							memo_b[vn[i]][vmb[i]] = cmb;
						}
					}
				}
				ret += memo_n[n][mb];
				b = (b&~(((1<<(N/2))-1)<<1)) + memo_b[n][mb];
				n = memo_node[n][mb];
			} else {
				ret++;
				int n2 = path[n][(b>>n)&1];
				b ^= (1<<n);
				n = n2;
			}
		}

		if (ret >= 1e18)
			cout << "Case #" << prob++ << ": Infinity" << endl;
		else
			cout << "Case #" << prob++ << ": " << ret << endl;
	}
}

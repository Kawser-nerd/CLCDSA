#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int ms[100][100], u[100], n, i, j, avail[100], k, tek, pr[100], Tn, Ti, m, root, q, x[10000], y[10000], pr2[100], avail2[100], new_tek;
string zc[100], s, tran_s, best;

void dfs (int k) {
	u[k] = 1;
	for(int j = 1; j <= n; j++) if (ms[k][j] && !u[j]) dfs(j);
}

bool still_okay () {
	int i;
	for(i = 1; i <= n; i++) u[i] = 0;
	for(i = 1; i <= n; i++) if (avail[i] > 0) u[i] = 1;
	for(i = 1; i <= n; i++) if (avail[i] == 1) dfs(i);
	for(i = 1; i <= n; i++) if (!u[i]) return false;
	return true;
}

void check_state_now (int t) {
	if (tran_s > s + zc[t]) {
		tran_s = s + zc[t];
		new_tek = t;
		for(int j = 1; j <= n; j++) {
			avail2[j] = avail[j];
			pr2[j] = pr[j];
		}
		avail2[t] = 1;
		pr2[t] = k;
	}
}

void greedy_minimum_check () {
	int i;
	for(i = 1; i <= n; i++) if (ms[k][i] && !avail[i]) check_state_now(i);
}

void make_choice () {
	k = tek;
	while (true) {
		if (still_okay()) greedy_minimum_check();
		if (pr[k]) {
			avail[k] = 2;
			k = pr[k];
		} else break;
	}
}

int main () {
	freopen("input.txt", "r", stdin);
	cin >> Tn;
	for(Ti = 1; Ti <= Tn; Ti++) {
		cin >> n >> m;
		for(i = 1; i <= n; i++) cin >> zc[i];
		memset(ms, 0, sizeof(ms));
		for(i = 1; i <= m; i++) {
			cin >> x[i] >> y[i];
			ms[x[i]][y[i]] = ms[y[i]][x[i]] = 1;
		}
		for(i = 1; i <= n; i++) {
			root = i;
			memset(avail, 0, sizeof(avail));
			memset(pr, 0, sizeof(pr));			
			s = zc[i];
			avail[i] = 1; tek = i;
			for(q = 1; q < n; q++) {
				tran_s = "x";
				make_choice();
				s = tran_s;
				for(j = 1; j <= n; j++) {
					pr[j] = pr2[j];
					avail[j] = avail2[j];
				}
				tek = new_tek;
			}
			if (i == 1) best = s; else best = min(best, s);
		}
		cout << "Case #" << Ti << ": " << best << endl;
	}
	return 0;
}

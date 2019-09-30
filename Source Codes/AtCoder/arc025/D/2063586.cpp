#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
#pragma warning (disable: 4996)

class Matrix {
public:
	long long dat[3][3]; int H, W;
	void init(int H1, int W1) {
		for (int i = 0; i < 3; i++) { for (int j = 0; j < 3; j++) dat[i][j] = 0; }
		H = H1; W = W1;
	}
};
Matrix Modmul(Matrix &A, Matrix &B, long long m) {
	Matrix C; C.init(A.H, B.W);
	for (int i = 0; i < A.H; i++) {
		for (int j = 0; j < B.W; j++) {
			for (int k = 0; k < A.W; k++) {
				C.dat[i][j] += A.dat[i][k] * B.dat[k][j];;
			}
		}
	}
	for (int i = 0; i < A.H; i++) {
		for (int j = 0; j < B.W; j++) C.dat[i][j] %= m;
	}
	return C;
}

Matrix AA[4][55];

Matrix Modpow(Matrix A, long long T, long long m, int ID) {
	Matrix C; C.init(A.H, A.W);
	for (int i = 0; i < A.H; i++) C.dat[i][i] = 1;
	long long J = 1;
	for (int i = 0; i < 50; i++) {
		if ((T&(1LL << i)) != 0) C = Modmul(C, AA[ID][i], m);
		J *= 2; if (J > T) break;
	}
	return C;
}
void init_2(long long m) {
	AA[0][0].init(2, 2); AA[0][0].dat[0][0] = 1; AA[0][0].dat[0][1] = 1; AA[0][0].dat[1][0] = 1; AA[0][0].dat[1][1] = 0;
	for (int i = 0; i < 54; i++)AA[0][i + 1] = Modmul(AA[0][i], AA[0][i], m);

	AA[1][0].init(3, 3);
	AA[1][0].dat[0][0] = 3; AA[1][0].dat[0][1] = 1; AA[1][0].dat[0][2] = 1000000006;
	AA[1][0].dat[1][0] = 1; AA[1][0].dat[1][1] = 0; AA[1][0].dat[1][2] = 0;
	AA[1][0].dat[2][0] = 0; AA[1][0].dat[2][1] = 1; AA[1][0].dat[2][2] = 0;
	for (int i = 0; i < 54; i++)AA[1][i + 1] = Modmul(AA[1][i], AA[1][i], m);
}

long long Fibonacci(long long n, long long m) {
	Matrix F; F.init(2, 2); F = AA[0][0];
	Matrix G; G.init(2, 1); G.dat[0][0] = 1; G.dat[1][0] = 1;
	Matrix J = Modpow(F, n, m, 0);
	Matrix I = Modmul(J, G, m);
	return I.dat[1][0];
}

long long Consent(long long n, long long pre, long long post, long long m) {
	if (pre == 0 && post == 0) {
		if (n < 0) return 0;
		Matrix A; A.init(3, 3); A = AA[1][0];
		Matrix B; B.init(3, 1); B.dat[0][0] = 7; B.dat[1][0] = 2; B.dat[2][0] = 1;
		Matrix J = Modpow(A, n, m, 1);
		Matrix I = Modmul(J, B, m);
		return I.dat[2][0];
	}
	else if (pre == 0 || post == 0) {
		if (n < 0) return 0;
		Matrix A; A.init(3, 3); A = AA[1][0];
		Matrix B; B.init(3, 1); B.dat[0][0] = 10; B.dat[1][0] = 3; B.dat[2][0] = 1;
		Matrix J = Modpow(A, n, m, 1);
		Matrix I = Modmul(J, B, m);
		return I.dat[2][0];
	}
	else if (pre == post) {
		if (n < 0) return 0;
		Matrix A; A.init(3, 3); A = AA[1][0];
		Matrix B; B.init(3, 1); B.dat[0][0] = 500000018; B.dat[1][0] = 500000008; B.dat[2][0] = 500000005;
		Matrix J = Modpow(A, n, m, 1);
		Matrix I = Modmul(J, B, m);
		if (n % 2 == 1) return (I.dat[2][0] - 500000004 + m) % m;
		if (n % 2 == 0) return (I.dat[2][0] + 500000004 + m) % m;
	}
	else {
		if (n < -1) return 0;
		if (n == -1) return 1;
		Matrix A; A.init(3, 3); A = AA[1][0];
		Matrix B; B.init(3, 1); B.dat[0][0] = 500000018; B.dat[1][0] = 500000008; B.dat[2][0] = 500000005;
		Matrix J = Modpow(A, n, m, 1);
		Matrix I = Modmul(J, B, m);
		if (n % 2 == 0) return (I.dat[2][0] - 500000004 + m) % m;
		if (n % 2 == 1) return (I.dat[2][0] + 500000004 + m) % m;
	}
}

long long modpow(long long p, long long q, long long m) {
	long long r1 = 1, r2 = p;
	for (int i = 0; i < 50; i++) {
		if ((q / (1LL << i)) % 2 == 1) { r1 *= r2; r1 %= m; }
		r2 *= r2; r2 %= m;
	}
	return r1;
}
long long Div(long long p, long long q, long long m) {
	return (p*modpow(q, m - 2, m)) % m;
}

long long H, W, Q, a[100009], b[100009], ret1, mod = 1000000007; bool used[3][100009]; int us[100009];
vector<long long>X1, E;

void query1(long long c2) {
	int pos3 = lower_bound(E.begin(), E.end(), c2) - E.begin();
	if (used[1][pos3] == false) {
		int pos1 = lower_bound(X1.begin(), X1.end(), c2) - X1.begin(); pos1--;
		int pos2 = pos1 + 1;
		long long prev_ = Fibonacci(X1[pos2] - X1[pos1] - 1, mod);
		long long T1 = Fibonacci(c2 - X1[pos1] - 1, mod);
		long long T2 = Fibonacci(X1[pos2] - c2 - 1, mod);
		ret1 = Div(ret1, prev_, mod);
		ret1 *= T1; ret1 %= mod;
		ret1 *= T2; ret1 %= mod;
		X1.clear(); used[1][pos3] = true;
		for (int i = 0; i < E.size(); i++) {
			if (used[1][i] == true) X1.push_back(E[i]);
		}
	}
	else {
		X1.clear(); used[1][pos3] = false;
		for (int i = 0; i < E.size(); i++) {
			if (used[1][i] == true) X1.push_back(E[i]);
		}
		int pos1 = lower_bound(X1.begin(), X1.end(), c2) - X1.begin(); pos1--;
		int pos2 = pos1 + 1;
		long long prev_ = Fibonacci(X1[pos2] - X1[pos1] - 1, mod);
		long long T1 = Fibonacci(c2 - X1[pos1] - 1, mod);
		long long T2 = Fibonacci(X1[pos2] - c2 - 1, mod);
		ret1 *= prev_; ret1 %= mod;
		ret1 = Div(ret1, T1, mod);
		ret1 = Div(ret1, T2, mod);
	}
}

long long nex[100009], nex_id[100009], dp[100009][2]; bool uses[3][100009];
vector<long long>F[100009], X2; vector<vector<vector<long long>>>s[100009];

int V[20009], cc = 0;

void add(int p1, int p2) {
	cc = 0;
	for (int i = 0; i < p2; i++) {
		if (us[i] >= 1) { V[cc] = i; cc++; }
	}
	for (int i = p2 + 1; i < E.size(); i++) {
		if (us[i] >= 1) { V[cc] = i; cc++; }
	}
	int pos1 = lower_bound(V, V + cc, p2) - V; pos1--;
	int pos2 = pos1 + 1;
	int pf1 = V[pos1], pf2 = V[pos2];
	if (used[1][p2] == false && used[2][p2] == false) {
		nex[V[pos1]] = p2;
		nex_id[V[pos1]] = lower_bound(F[V[pos1]].begin(), F[V[pos1]].end(), p2) - F[V[pos1]].begin();
		nex[p2] = V[pos2];
		nex_id[p2] = lower_bound(F[p2].begin(), F[p2].end(), V[pos2]) - F[p2].begin();
	}
	used[p1][p2] = true; us[p2]++;

	for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) { s[pf1][nex_id[pf1]][i][j] = 0; } }
	for (int i = 0; i < 3; i++) {
		if (i == 1 && used[1][pf1] == true) continue;
		if (i == 2 && used[2][pf1] == true) continue;
		for (int j = 0; j < 3; j++) {
			if (j == 1 && used[1][p2] == true) continue;
			if (j == 2 && used[2][p2] == true) continue;
			int s1 = 1 - min(i, 1); if (used[1][pf1] == true && used[2][pf1] == true) s1 = 1;
			int t1 = min(j, 1); if (used[1][p2] == true && used[2][p2] == true) t1 = 1;

			int u1 = 1, v1 = i, w1 = j;
			if (t1 == 1 && (used[1][p2] == false || used[2][p2] == false)) {
				u1 = 2;
				if (w1 == 1) w1 = 2; else w1 = 1;
			}
			s[pf1][nex_id[pf1]][s1][t1] += Consent(E[p2] - E[pf1] - u1, v1, w1, mod);
		}
	}
	for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) { s[p2][nex_id[p2]][i][j] = 0; } }
	for (int i = 0; i < 3; i++) {
		if (i == 1 && used[1][p2] == true) continue;
		if (i == 2 && used[2][p2] == true) continue;
		for (int j = 0; j < 3; j++) {
			if (j == 1 && used[1][pf2] == true) continue;
			if (j == 2 && used[2][pf2] == true) continue;
			int s1 = 1 - min(i, 1); if (used[1][p2] == true && used[2][p2] == true) s1 = 1;
			int t1 = min(j, 1); if (used[1][pf2] == true && used[2][pf2] == true) t1 = 1;

			int u1 = 1, v1 = i, w1 = j;
			if (t1 == 1 && (used[1][pf2] == false || used[2][pf2] == false)) {
				u1 = 2;
				if (w1 == 1) w1 = 2; else w1 = 1;
			}
			s[p2][nex_id[p2]][s1][t1] += Consent(E[pf2] - E[p2] - u1, v1, w1, mod);
		}
	}
}
void lose(int p1, int p2) {
	cc = 0;
	for (int i = 0; i < p2; i++) {
		if (us[i] >= 1) { V[cc] = i; cc++; }
	}
	for (int i = p2 + 1; i < E.size(); i++) {
		if (us[i] >= 1) { V[cc] = i; cc++; }
	}
	int pos1 = lower_bound(V, V + cc, p2) - V; pos1--;
	int pos2 = pos1 + 1;
	int pf1 = V[pos1], pf2 = V[pos2];
	if (used[1][p2] == false || used[2][p2] == false) {
		nex[pf1] = pf2;
		nex_id[pf1] = lower_bound(F[pf1].begin(), F[pf1].end(), pf2) - F[pf1].begin();
	}
	used[p1][p2] = false; us[p2]--;
	if (nex[pf1] == pf2) {
		for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) { s[pf1][nex_id[pf1]][i][j] = 0; } }
		for (int i = 0; i < 3; i++) {
			if (i == 1 && used[1][pf1] == true) { continue; }
			if (i == 2 && used[2][pf1] == true) { continue; }
			for (int j = 0; j < 3; j++) {
				if (j == 1 && used[1][pf2] == true) continue;
				if (j == 2 && used[2][pf2] == true) continue;
				int s1 = 1 - min(i, 1); if (used[1][pf1] == true && used[2][pf1] == true) s1 = 1;
				int t1 = min(j, 1); if (used[1][pf2] == true && used[2][pf2] == true) t1 = 1;

				int u1 = 1, v1 = i, w1 = j;
				if (t1 == 1 && (used[1][pf2] == false || used[2][pf2] == false)) {
					u1 = 2;
					if (w1 == 1) w1 = 2; else w1 = 1;
				}
				s[pf1][nex_id[pf1]][s1][t1] += Consent(E[pf2] - E[pf1] - u1, v1, w1, mod);
			}
		}
	}
	else {
		for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) { s[pf1][nex_id[pf1]][i][j] = 0; } }
		for (int i = 0; i < 3; i++) {
			if (i == 1 && used[1][pf1] == true) continue;
			if (i == 2 && used[2][pf1] == true) continue;
			for (int j = 0; j < 3; j++) {
				if (j == 1 && used[1][p2] == true) continue;
				if (j == 2 && used[2][p2] == true) continue;
				int s1 = 1 - min(i, 1); if (used[1][pf1] == true && used[2][pf1] == true) s1 = 1;
				int t1 = min(j, 1); if (used[1][p2] == true && used[2][p2] == true) t1 = 1;

				int u1 = 1, v1 = i, w1 = j;
				if (t1 == 1 && (used[1][p2] == false || used[2][p2] == false)) {
					u1 = 2;
					if (w1 == 1) w1 = 2; else w1 = 1;
				}
				s[pf1][nex_id[pf1]][s1][t1] += Consent(E[p2] - E[pf1] - u1, v1, w1, mod);
			}
		}
		for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) { s[p2][nex_id[p2]][i][j] = 0; } }
		for (int i = 0; i < 3; i++) {
			if (i == 1 && used[1][p2] == true) continue;
			if (i == 2 && used[2][p2] == true) continue;
			for (int j = 0; j < 3; j++) {
				if (j == 1 && used[1][pf2] == true) continue;
				if (j == 2 && used[2][pf2] == true) continue;
				int s1 = 1 - min(i, 1); if (used[1][p2] == true && used[2][p2] == true) s1 = 1;
				int t1 = min(j, 1); if (used[1][pf2] == true && used[2][pf2] == true) t1 = 1;

				int u1 = 1, v1 = i, w1 = j;
				if (t1 == 1 && (used[1][pf2] == false || used[2][pf2] == false)) {
					u1 = 2;
					if (w1 == 1) w1 = 2; else w1 = 1;
				}
				s[p2][nex_id[p2]][s1][t1] += Consent(E[pf2] - E[p2] - u1, v1, w1, mod);
			}
		}
	}
}

int bit[100009];

void adds(int pos, int x) {
	pos++;
	while (pos <= 100000) { bit[pos] += x; pos += (pos&-pos); }
}
int sums(int pos) {
	int ss = 0; pos++;
	while (pos >= 1) { ss += bit[pos]; pos -= (pos&-pos); }
	return ss;
}
int lowers_1(int pos) {
	int L = pos + 1, R = 100000, M, minx = 1000000;
	int u = sums(pos);
	for (int i = 0; i < 20; i++) {
		M = (L + R) / 2;
		if (sums(M) > u) { minx = min(minx, M); R = M; }
		else { L = M; }
	}
	return minx;
}
int lowers_2(int pos) {
	int L = 0, R = pos, M, minx = -1;
	int u = sums(pos);
	for (int i = 0; i < 20; i++) {
		M = (L + R) / 2;
		if (sums(M - 1) < u) { minx = max(minx, M); L = M; }
		else { R = M; }
	}
	return minx;
}

void init() {
	F[0].push_back(E.size() - 1); adds(0, 1); adds(E.size() - 1, 1);
	uses[1][0] = true; uses[1][E.size() - 1] = true;
	uses[2][0] = true; uses[2][E.size() - 1] = true;
	for (int i = 1; i <= Q; i++) {
		int pos1 = lower_bound(E.begin(), E.end(), b[i]) - E.begin();
		if (uses[a[i]][pos1] == false) {
			int pos2 = lowers_2(pos1);
			int pos3 = lowers_1(pos2);
			F[pos2].push_back(pos1);
			F[pos1].push_back(pos3);
			if (uses[1][pos1] == false && uses[2][pos1] == false) adds(pos1, 1);
			uses[a[i]][pos1] = true;
		}
		else {
			uses[a[i]][pos1] = false;
			if (uses[1][pos1] == false && uses[2][pos1] == false) adds(pos1, -1);
			int pos2 = lowers_2(pos1);
			int pos3 = lowers_1(pos2);
			F[pos2].push_back(pos3);
		}
	}
	for (int i = 0; i < E.size(); i++) {
		sort(F[i].begin(), F[i].end());
		F[i].erase(unique(F[i].begin(), F[i].end()), F[i].end());
		s[i].resize(F[i].size(), vector<vector<long long>>(2, vector<long long>(2, 0)));
	}
}

long long query2(long long c1, long long c2) {
	int pos1 = lower_bound(E.begin(), E.end(), c2) - E.begin();
	if (used[c1][pos1] == false) {
		add(c1, pos1);
	}
	else if (used[c1][pos1] == true) {
		lose(c1, pos1);
	}
	//for (int i = 0; i < E.size(); i++) { dp[i][0] = 0; dp[i][1] = 0; }
	dp[0][1] = 1; dp[0][0] = 0;
	int cx = 0;
	while (cx < E.size() - 1) {
		dp[nex[cx]][0] = (dp[cx][0] * s[cx][nex_id[cx]][0][0] + dp[cx][1] * s[cx][nex_id[cx]][1][0]) % mod;
		dp[nex[cx]][1] = (dp[cx][0] * s[cx][nex_id[cx]][0][1] + dp[cx][1] * s[cx][nex_id[cx]][1][1]) % mod;
		cx = nex[cx];
	}
	return dp[E.size() - 1][1];
}

int main() {
	cin >> H >> W >> Q;
	init_2(mod);
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld", &a[i], &b[i]);
		E.push_back(b[i]);
	}
	E.push_back(0); E.push_back(W + 1);
	sort(E.begin(), E.end());
	E.erase(unique(E.begin(), E.end()), E.end());
	if (H == 1) {
		ret1 = Fibonacci(W, mod);
		used[1][0] = true; used[1][E.size() - 1] = true;
		X1.push_back(0); X1.push_back(W + 1);
		for (int i = 1; i <= Q; i++) {
			query1(b[i]);
			printf("%lld\n", ret1);
		}
	}
	if (H == 2) {
		init();
		used[1][0] = true; used[1][E.size() - 1] = true;
		used[2][0] = true; used[2][E.size() - 1] = true;
		us[0] = 2; us[E.size() - 1] = 2;
		for (int i = 1; i <= Q; i++) {
			printf("%lld\n", query2(a[i], b[i]));
		}
	}
	return 0;
} ./Main.cpp:98:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.
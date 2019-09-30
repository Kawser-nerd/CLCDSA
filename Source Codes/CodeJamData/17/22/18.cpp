
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
string solve2(int N, int R, int Y, int B) {
	if (N == 1) {
		if (R == 1) return "R";
		if (Y == 1) return "Y";
		if (B == 1) return "B";
	}
	vector<pair<int, string> > S;
	S.push_back(make_pair(R, "R"));
	S.push_back(make_pair(Y, "Y"));
	S.push_back(make_pair(B, "B"));
	sort(S.begin(), S.end());

	string res = "";
	if (S[2].first > S[0].first + S[1].first) return "";

	while (S[2].first > 0) {
		res += S[2].second;
		S[2].first--;
		int ot = 0;
		for (int a = 0; a <= 1; a++) {
			if (S[a].first > S[2].first) {
				res += S[a].second;
				S[a].first--;
				ot = 1;
			}
		}
		if (ot == 0) {
			if (S[1].first <= S[0].first) {
				res += S[0].second;
				S[0].first--;
			}
			else {
				res += S[1].second;
				S[1].first--;
			}
		}
	}
	return res;
}
string solve(int N, int R, int O, int Y, int G ,int B ,int V) {
	if (N == 1) {
		if (R == 1) return "R";
		if (Y == 1) return "Y";
		if (B == 1) return "B";

		if (O == 1) return "O";
		if (G == 1) return "G";
		if (V == 1) return "V";
	}
	string res = "";
	for (int i = 0; i < 3; i++) {
		int *P, *Q;
		string str = "";
		if (i == 0) { P = &V; Q = &Y; str = "VY"; }
		else if (i == 1) { P = &O; Q = &B; str = "OB"; }
		else { P = &G; Q = &R; str = "GR"; }
		if (*P > 0) {
			*Q -= *P;
			if (*Q == 0) {
				if ((*P) * 2 == N) {
					for (int i = 0; i < (*P); i++) res += str;
					return res;
				}
				else {
					return "";
				}
			}
			if (*Q < 0) return "";
		}
	}
	res = solve2(N, R, Y, B);
	if (res.size() == 0) return "";
	for (int i = 0; i < 3; i++) {
		int *P, *Q;
		string str = "";
		if (i == 0) { P = &V; Q = &Y; str = "VY"; }
		else if (i == 1) { P = &O; Q = &B; str = "OB"; }
		else { P = &G; Q = &R; str = "GR"; }

		if (*P > 0) {
			string tmp = res;
			bool first = true;
			res = "";
			for (int j = 0; j < tmp.size(); j++) {
				res += tmp[j];
				if (first && tmp[j] == str[1]) {
					for (int i = 0; i < (*P); i++) res += str;
					first = false;
				}
			}
		}
	}
	return res;
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int N, R, O, Y, G, B, V;
	while (T-- > 0) {
		scanf("%d %d %d %d %d %d %d", &N, &R, &O, &Y, &G, &B, &V);
		string sol = solve(N, R, O, Y, G, B, V);
		static int cs = 1;
		if (sol.size() == 0) sol = "IMPOSSIBLE";
		else if (sol.size() != N) fprintf(stderr, "ERROR %d : %d %d %d %d %d %d %d => %s\n", cs, N, R, O, Y, G, B, V, sol.c_str());
		printf("Case #%d: %s\n", cs++, sol.c_str());
	}
	return 0;
}
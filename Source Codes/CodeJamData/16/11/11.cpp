#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <string.h>
using namespace std;

string solve(string S) {
	int len = (int)S.size();
	if (len <= 1) return S;
	char mx = S[0];
	for (int i = 0; i < len; i++) {
		if (S[i] > mx) mx = S[i];
	}
	for (int i = 0; i < len; i++) {
		if (S[i] == mx) {
			string front = "", G = "";
			for (int j = i; j < len; j++) {
				if (S[j] == mx) front += mx;
				else G += S[j];
			}
			return front + solve(S.substr(0, i)) + G;
		}
	}
}
int main() {
	char inp[1024];
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int N;
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s", inp);
		string res = solve(inp);
		if (res.size() != strlen(inp)) fprintf(stderr, "ERROR");
		printf("Case #%d: %s\n", tc, res.c_str());
	}
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;

int N, R, P, S;

string succ(string st)
{
	string ret;
	for (char c : st) {
		if (c == 'S') ret += "PS";
		else if (c == 'P') ret += "PR";
		else if (c == 'R') ret += "RS";
	}
	return ret;
}

bool isok(string s)
{
	int nr = 0, np = 0, ns = 0;
	for (char c : s) {
		if (c == 'S') ++ns;
		else if (c == 'R') ++nr;
		else if (c == 'P') ++np;
	}
	return R == nr && P == np && S == ns;
}

string reorder(string s)
{
	if (s.size() == 1) return s;
	string top, end;
	for (int i = 0; i < s.size() / 2; ++i) top.push_back(s[i]);
	for (int i = 0; i < s.size() / 2; ++i) end.push_back(s[i + s.size() / 2]);
	top = reorder(top);
	end = reorder(end);
	if (top > end) return end + top;
	return top + end;
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;) {
		scanf("%d%d%d%d", &N, &R, &P, &S);

		string ans = "IMPOSSIBLE";
		for (char c : {'P', 'R', 'S'}) {
			string init;
			init.push_back(c);
			for (int i = 0; i < N; ++i) init = succ(init);
			if (isok(init)) {
				string cand = reorder(init);
				if (ans[0] == 'I') ans = cand;
				else ans = min(ans, cand);
			}
		}

		printf("Case #%d: %s\n", t, ans.c_str());
	}

	return 0;
}

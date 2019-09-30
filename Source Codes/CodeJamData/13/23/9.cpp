#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int borsize = 1000 * 1000 * 5;
const int size = 10 * 1000;
const int inf = 1000 * 1000 * 1000;

int ways[borsize][26];
int borlen = 1;
bool terminal[borsize];
int ans[size][10];
string str;

void dfs(int ps, int strps, int len, int a) {
	if (terminal[ps])
		ans[strps][len] = min(ans[strps][len], a);
	if (strps >= str.size())
		return;
	for (int i = 0; i < 26; i++)
		if (ways[ps][i] != -1)
			if (str[strps] == char('a' + i))
				dfs(ways[ps][i], strps + 1, min(len + 1, 5), a);
			else
				if (len == 5)
					dfs(ways[ps][i], strps + 1, 1, a + 1);
}

int main() {
	freopen("problem_c.in", "r", stdin);
	freopen("problem_c.out", "w", stdout);
		
	for (int i = 0; i < 26; i++)
		ways[0][i] = -1;

	//FILE *f1 = fopen("dictionary.in", "r");
	//ifstream ifile("dictionary.in");
	while (cin >> str) {
		int ptr = 0;
		for (int i = 0; i < str.size(); i++) {
			if (ways[ptr][str[i] - 'a'] == -1) {
				for (int j = 0; j < 26; j++)
					ways[borlen][j] = -1;
				borlen++;
				ways[ptr][str[i] - 'a'] = borlen - 1;
			}
			ptr = ways[ptr][str[i] - 'a'];
		}

		terminal[ptr] = true;

		if (str == "zymuznh")
			break;
	}

	cerr << "wasted!" << endl;
		
	int tc;
	cin >> tc;
	for (int tnum = 0; tnum < tc; tnum++) {
		cin >> str;
		cerr << str << endl;
		for (int i = 0; i <= str.size(); i++)
			for (int j = 0; j <= 5; j++)
				ans[i][j] = inf;
		ans[0][5] = 0;
		for (int i = 0; i < str.size(); i++)
			for (int j = 0; j <= 5; j++)
				if (ans[i][j] != inf)
					dfs(0, i, j, ans[i][j]);
		int best = inf;
		for (int j = 0; j <= 5; j++)
			best = min(best, ans[str.size()][j]);
		cout << "Case #" << tnum + 1 << ": " << best << endl;
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath> D
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

void read_data(int test) {
}

const int maxN = 2100;
int n;
string s[maxN];

void solve(int test) {
	cin >> n;
	n += n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	set < string > a, b;
	map < string, int > x, y;
	for (int i = 0; i < n; ++i) {
		string s1 = "", s2 = "";
		for (int j = 0; j < n; ++j) {
			s1 += s[i][j];
			s2 += s[j][i];
		}

		if (count(s1.begin(), s1.end(), '0') != n / 2) {
			printf("Case #%d: IMPOSSIBLE\n", test);
			return ;
		}
		if (count(s2.begin(), s2.end(), '0') != n / 2) {
			printf("Case #%d: IMPOSSIBLE\n", test);
			return;
		}
		a.insert(s1);
		b.insert(s2);

		++x[s1];
		++y[s2];
	}

	if (a.size() != 2 || b.size() != 2) {
		printf("Case #%d: IMPOSSIBLE\n", test);
		return;
	}

	int res = 0;
	{
		set < string > ::iterator it = a.begin();
		string s1 = *it;
		++it;
		string s2 = *it;

		for (int i = 0; i < n; ++i) {
			if (s1[i] == s2[i]) {
				printf("Case #%d: IMPOSSIBLE\n", test);
				return;
			}
		}

		int u = x[s1];
		int v = x[s2];

		if (abs(u - v) > 0) {
			printf("Case #%d: IMPOSSIBLE\n", test);
			return;
		}

		int p0 = 0, p1 = 0;
		for (int i = 0; i < n; ++i) {
			if (s1[i] != '0' + (i % 2)) {
				++p0;
			}
			if (s1[i] != '0' + ((i + 1) % 2)) {
				++p1;
			}
		}
		res += min(p0, p1);
	}

	{
		set < string > ::iterator it = b.begin();
		string s1 = *it;
		++it;
		string s2 = *it;

		for (int i = 0; i < n; ++i) {
			if (s1[i] == s2[i]) {
				printf("Case #%d: IMPOSSIBLE\n", test);
				return;
			}
		}

		int u = y[s1];
		int v = y[s2];

		if (abs(u - v) > 0) {
			printf("Case #%d: IMPOSSIBLE\n", test);
			return;
		}

		int p0 = 0, p1 = 0;
		for (int i = 0; i < n; ++i) {
			if (s1[i] != '0' + (i % 2)) {
				++p0;
			}
			if (s1[i] != '0' + ((i + 1) % 2)) {
				++p1;
			}
		}
		res += min(p0, p1);
	}

	printf("Case #%d: %d\n", test, res / 2);
}

int main(int argc, char* argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//freopen("input.txt", "r", stdin);
	//freopen(argv[3], "w", stdout);

	int left_bound, right_bound;
	//sscanf(argv[1], "%d", &left_bound);
	//sscanf(argv[2], "%d", &right_bound);

	int tests;
	scanf("%d", &tests);
	left_bound = 1;
	right_bound = tests;
	for (int i = 1; i <= tests; ++i) {
		if (i >= left_bound && i <= right_bound) {
			solve(i);
			cerr << i << ": " << clock() << endl;
		}
		else {
			read_data(i);
		}
	}
	return 0;
}
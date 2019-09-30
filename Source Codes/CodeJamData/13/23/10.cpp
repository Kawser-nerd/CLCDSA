#pragma comment(linker, "/STACK:128777216")

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <numeric>
#include <sstream>
#include <exception>
#include <cassert>

typedef long long i64;
typedef unsigned int u32;
const int null = 0;

using namespace std;

template<class T> int size(const T &a) {
	return int(a.size());
}
template<class T> T abs(const T &a) {
	return (a < 0? -a: a);
}
template<class T> T sqr(const T &a) {
	return a * a;
}

#define all(a) a.begin(),a.end()

struct Node {
	bool isWord;
	Node* next[26];
} nodes[1200000], *enode = nodes, *head = enode++;

char s[10000];

void initV() {
	FILE* fin = fopen("words.txt", "r");
	int n;
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%s", s);
		Node* w = head;
		for (int i = 0; s[i]; i++) {
			int c = s[i] - 'a';
			if (w->next[c] == null) {
				w->next[c] = enode++;
			}
			w = w->next[c];
		}
		w->isWord = true;
	}
	fclose(fin);
	fprintf(stderr, "nodes: %d\n", (enode - nodes));
}

int dp[16][1200000];

void up(int i, Node* t, int d) {
	int j = t - nodes;
	if (dp[i & 15][j] > d) {
		dp[i & 15][j] = d;
	}
}

void add(int i, Node* w, int d, int k) {
	if (k == 0) {
		up(i, w, d);
		return;
	}
	int c = s[i] - 'a';
	w = w->next[c];
	if (w) {
		add(i + 1, w, d, k - 1);
		if (w->isWord) {
			add(i + 1, head, d, k - 1);
		}
	}
}

int main() {
#ifdef pperm
	freopen("input.txt", "r", stdin);
	//freopen("input.txt", "w", stdout);
	freopen("output.txt", "w", stdout);
#endif
	initV();
	int m = enode - nodes;
	int T;
	scanf("%d", &T);
	for (int iTest = 1; iTest <= T; iTest++) {
		printf("Case #%d: ", iTest);
		scanf("%s", s);
		int n = strlen(s);
		memset(dp, 127, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			int c = s[i] - 'a';
			memset(dp[(i + 8) & 15], 127, sizeof(dp[0]));
			for (int j = 0; j < m; j++) {
				if (dp[i & 15][j] > n) {
					continue;
				}
				Node* w = nodes + j;
				add(i, w, dp[i & 15][j], 1);
				w = nodes + j;
				for (int k = 0; k < 26; k++) {
					Node* t = w->next[k];
					if (t) {
						int q = min(n - i - 1, 4);
						add(i + 1, t, dp[i & 15][j] + 1, q);
						if (t->isWord) {
							add(i + 1, head, dp[i & 15][j] + 1, q);
						}
					}
				}
			}
		}
		printf("%d\n", dp[n & 15][0]);
	}
#ifdef pperm
	fprintf(stderr, "\n%.3lf\n", clock() / double(CLOCKS_PER_SEC));
#endif
	return 0;
}
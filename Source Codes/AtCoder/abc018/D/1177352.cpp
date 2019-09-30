#include<iostream>
#include<unordered_map>
#include<cstdio>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int a, b, c, d, e;
int x[324], y[324], z[324];
int MAX = 0;
vector<int>V;
void DFS(int n) {
	if (a == n) {
		if (V.size() == c) {
			bool k[18]{};
			for (int i = 0; i < c; i++) {
				k[V[i]] = true;
			}
			int kati[18]{};
			for (int i = 0; i < e; i++) {
				if (k[x[i]])kati[y[i]] += z[i];
			}
			sort(kati, kati + b, greater<int>());
			int sum = 0;
			for (int i = 0; i < d; i++) {
				sum += kati[i];
			}
			MAX = max(MAX, sum);
		}
		return;
	}
	DFS(n + 1);
	V.push_back(n);
	DFS(n + 1);
	V.pop_back();
}
signed main() {
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	for (int f = 0; f < e; f++) {
		scanf("%d%d%d", &x[f], &y[f], &z[f]);
		x[f]--; y[f]--;
	}
	DFS(0);
	printf("%d\n", MAX);
}
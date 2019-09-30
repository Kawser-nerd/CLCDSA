#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<math.h>
#include<queue>
#include<functional>
#define p pair<int,int>
#define P pair<p,p>
using namespace std;

double mincost[1000][1000];
P T[1000];
signed main() {
	int a; scanf("%d", &a);
	for (int b = 0; b < a; b++) {
		scanf("%d%d%d%d", &T[b].first.first, &T[b].first.second, &T[b].second.first, &T[b].second.second);
	}
	for (int b = 0; b < a; b++) {
		for (int c = 0; c < a; c++) {
			if (b == c)mincost[b][c] = 0;
			else {
				mincost[b][c] = sqrt((T[b].first.first - T[c].first.first)*(T[b].first.first - T[c].first.first) + (T[b].first.second - T[c].first.second)*(T[b].first.second - T[c].first.second)) / min(T[b].second.first, T[c].second.second);
			}
		}
	}
	for (int x = 0; x < a; x++) {
		for (int y = 0; y < a; y++) {
			for (int z = 0; z < a; z++) {
				mincost[y][z] = min(mincost[y][z], mincost[y][x] + mincost[x][z]);
			}
		}
	}
	vector<double>V;
	for (int i = 1; i < a; i++) {
		V.push_back(mincost[0][i]);
	}
	sort(V.begin(), V.end(), greater<double>());
	double ans = 0;
	for (int i = 0; i < a - 1; i++) {
		ans = max(ans, V[i] + i);
	}
	printf("%.15lf\n", ans);
}
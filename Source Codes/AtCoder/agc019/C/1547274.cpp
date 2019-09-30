#include<iostream>
#include<algorithm>
#include<cstdio>
#include<functional>
#include<vector>
#include<map>
#include<string>
#include<math.h>
#include<set>
#include<string.h>
#include<unordered_set>
#include<unordered_map>
#define int long long
#define P pair<int,int>
using namespace std;

P S, G;
P k[200000];
vector<int>V;
int dp[200001];
signed main() {
	bool T = false;
	cin >> S.first >> S.second;
	cin >> G.first >> G.second;
	if (abs(S.first - G.first) <= 1) {
		T = true;
		swap(S.first, S.second);
		swap(G.first, G.second);
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k[i].first >> k[i].second;
		if (T)swap(k[i].first, k[i].second);
	}
	if (S.first > G.first)swap(S, G);
	sort(k, k + n);
	double M = 0;
	if (S.second == G.second) {
		for (int i = 0; i < n; i++) {
			if (k[i].second == S.second&&k[i].first >= S.first&&k[i].first <= G.first) {
				M += 20 * M_PI*0.5 - 20;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (G.first >= k[i].first&&S.first <= k[i].first&&max(S.second, G.second) >= k[i].second&&min(S.second, G.second) <= k[i].second) {
			if (S.second < G.second)V.push_back(k[i].second);
			if (S.second > G.second)V.push_back(10000000000-k[i].second);
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < V.size(); i++) {
		*lower_bound(dp, dp + n, V[i]) = V[i];
	}
	int i = 0;
	for (i = V.size(); i >= 0; i--) {
		if (dp[i] <= 1000000000000ll)break;
	}	
	if (i == min(G.first - S.first, abs(G.second - S.second))+1) {
		printf("%.50lf\n", (G.first - S.first + abs(G.second - S.second)) * 100 - (20 - 5 * M_PI)*(i-1) + 20 * M_PI*0.5 - 20+M);
	}
	else { printf("%.50lf\n", (G.first - S.first + abs(G.second - S.second)) * 100 - (20 - 5 * M_PI)*i + M); }
}
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <iomanip>
#include <algorithm>
using namespace std;

constexpr int INF       = 1000000000;/* 1e+9a */
constexpr int MODULO    = 1000000007;

typedef int64_t ll;


#define SPRE(x) setprecision(x) // ?????

int main()
{
	cin.tie(0);
    ios::sync_with_stdio(false);
	array<int, 100010> sc{};
	int n, c;
	cin >> n >> c;
	vector<vector<pair<int,int>>> times(c,vector<pair<int,int>>());
	for (int i = 0; i < n; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		times[c-1].push_back({s,t});
	}
	for(auto&& t : times){
		sort(t.begin(), t.end());
	}
	for(auto&& t : times){
		if(t.size() == 0)
			continue;
		sc[t[0].first-1]++;
		sc[t[0].second]--;
		for (int i = 1; i < t.size(); i++) {
			if(t[i-1].second == t[i].first)
				sc[t[i].first]++;
			else
				sc[t[i].first-1]++;
			sc[t[i].second]--;
		}
	}
	int maxim = 0;
	for (int i = 1; i < sc.size(); i++) {
		sc[i] += sc[i-1];
		maxim = max(maxim, sc[i]);
	}
	cout << maxim << '\n';
}
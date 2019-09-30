#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long int;

const LL MOD = 1000000007;

LL mpow(LL a, LL x) {
	if (x == 0)return 1;
	LL half = mpow(a, x / 2);
	half *= half;
	half %= MOD;
	if (x % 2) {
		half *= a;
		half %= MOD;
	}
	return half;
}


int N;
int par[222222];
vector<int>child[222222];
int vnum[222222];
int cnt[222222];
int dep[222222];

void dfs(int v, int cou) {
	dep[v] = cou;
	for (int ch : child[v]) {
		dfs(ch, cou + 1);
	}
}

struct node {
	LL nil, one;
	LL sum;
};

node operator+(const node&n1, const node&n2) {
	LL nil = (n1.nil * n2.nil) % MOD;
	LL one = (n1.nil * n2.one + n1.one * n2.nil) % MOD;
	return {
		nil,one,n1.sum + n2.sum
	};
}

void merge(vector<node> &prime, vector<node> &brnch) {
	assert(prime.size() >= brnch.size());
	int diff = prime.size() - brnch.size();
	for (int i = 0; i < brnch.size(); ++i) {
		node grow = prime[i + diff] + brnch[i];
		prime[i + diff] = grow;
	}
}

//yes,no
vector<node> dp(int v) {
	if (child[v].empty()) {
		return vector<node>(1, { 1,1,1 });
	}
	/*
	vector<node>res = dp(child[v][0]);

	for (int i = 1; i < child[v].size(); ++i) {
	vector<node>tmp = dp(child[v][i]);
	if (tmp.size() > res.size()) {
	merge(tmp, res);
	//res = move(tmp);
	swap(res, tmp);
	}
	else {
	merge(res, tmp);
	}
	}
	*/
	vector<pair<int, int>>srt;
	vector<vector<node>>tame;
	for (int ch : child[v]) {
		tame.emplace_back(dp(ch));
		srt.push_back({ tame.back().size(),tame.size() - 1 });
	}
	sort(srt.begin(), srt.end());
	//vector<node>&res = tame[srt[0].second];
	int las = 0;
	for (int i = 1; i < srt.size(); ++i) {
		//vector<node>&tmp = tame[srt[i].second];
		/*
		if (tmp.size() > res.size()) {
		merge(tmp, res);
		res = move(tmp);
		//swap(res, tmp);
		}
		else {
		merge(res, tmp);
		}
		*/
		merge(tame[srt[i].second], tame[srt[i - 1].second]);
		las = tame[srt[i - 1].second].size();
	}
	vector<node>&res = tame[srt[srt.size() - 1].second];
	int cnt = 0;
	for (auto itr = res.rbegin(); itr != res.rend(); ++itr) {
		if (cnt >= las)break;
		LL zero = mpow(2, itr->sum) + MOD;
		zero = (zero - itr->one) % MOD;
		itr->nil = zero;
		cnt++;
	}
	res.push_back({ 1,1,1 });
	return std::move(res);
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> par[1 + i];
		child[par[1 + i]].push_back(i + 1);
	}
	dfs(0, 0);
	vector<node> ans = dp(0);
	for (int i = 0; i <= N; ++i) {
		cnt[dep[i]]++;
	}
	LL answer = 0;
	for (int i = 0; i < ans.size(); ++i) {
		LL kis = N + 1 - cnt[ans.size() - 1 - i];
		kis = mpow(2, kis);
		kis *= ans[i].one;
		kis %= MOD;
		answer += kis;
		answer %= MOD;
	}
	cout << answer << endl;
	return 0;
}
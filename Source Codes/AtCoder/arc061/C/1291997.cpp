#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<functional>
#define p pair<int,int>
#define P pair<int,p>//from kaisya ID
using namespace std;

vector<p>rinsetu[500000];
P B[400000];
int mincost[500000];
vector<int>ans;
signed main() {
	int a, b; scanf("%d%d", &a, &b);
	//?????
	//???????????????
	for (int c = 0; c < b; c++) {
		int d, e, f; scanf("%d%d%d", &d, &e, &f); d--; e--;
		if (d > e)swap(d, e);
		if (e == a - 1) {
			ans.push_back(a + c * 2 + 1);
		}
		rinsetu[d].push_back({ 1,a + c * 2 });
		rinsetu[a + c * 2].push_back({ 0,d });
		rinsetu[e].push_back({ 1,a + c * 2+1 });
		rinsetu[a + c * 2 + 1].push_back({ 0,e });
		rinsetu[a + c * 2].push_back({ 0,a + c * 2 + 1 });
		rinsetu[a + c * 2 + 1].push_back({ 0,a + c * 2 });
		B[c * 2] = { d,{ f,a + c * 2 + 1 } };
		B[c * 2 + 1] = { e,{f,a + c * 2} };
	}
	sort(B, B + b * 2);
	for (int i = 1; i < b * 2; i++) {
		if (B[i].first == B[i - 1].first&&B[i].second.first == B[i - 1].second.first) {
			rinsetu[B[i].second.second].push_back({ 0,B[i - 1].second.second });
			rinsetu[B[i-1].second.second].push_back({ 0,B[i].second.second });
		}
	}
	memset(mincost, 0x3f, sizeof(mincost));
	mincost[0] = 0;
	priority_queue<p, vector<p>, greater<p>>Q;
	Q.push({ 0,0 });
	while (Q.size()) {
		p i = Q.top(); Q.pop();
		for (p t : rinsetu[i.second]) {
			if (mincost[t.second] > mincost[i.second] + t.first) {
				mincost[t.second] = mincost[i.second] + t.first;
				Q.push({ mincost[i.second] + t.first, t.second });
			}
		}
	}
	int MIN = 1 << 29;
	for (int i : ans) {
		MIN = min(MIN, mincost[i]);
	}
	if (MIN == 1 << 29)puts("-1");
	else cout << MIN << endl;
}
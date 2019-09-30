#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPL(i,f,n) for(int i=f, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
typedef vector<long long> vll;

// ?????
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	return a/ gcd(a,b)*b;
}
bool vis[60];
bool graph[60][60];
int N;
void dfs(int x) { // ?????
	if (vis[x])return;
	vis[x] = true; // ??x????????
	REP(i, N) { //??i:??x??????? do
		if (graph[x][i]) {
			dfs(i);
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int M,ans = 0,a[60], b[60];
	scanf("%d %d", &N, &M);
	REP(i, M) {
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
		graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
	}
	REP(j, M) {
		graph[a[j]][b[j]] = graph[b[j]][a[j]] = false;
		REP(i, N) vis[i] = false;
		dfs(0);
		bool connected = true;
		REP(i, N) {
			if (!vis[i]) {
				connected = false;
			}
		}
		if (!connected)ans++;
		graph[a[j]][b[j]] = graph[b[j]][a[j]] = true;
	}
	cout << ans << endl;
	return 0;
}
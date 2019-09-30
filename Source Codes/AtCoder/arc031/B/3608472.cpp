#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPL(i,f,n) for(int i=f, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

const int N = 10;
int vy[4] = { 1,0,-1, 0 };
int vx[4] = { 0,1, 0,-1 };
int oCnt = 0; // ????
bool board[10][10];
bool ok(int y, int x) {
	return y >= 0 && x >= 0 && y < N && x < N;
}
bool check(int y, int x) {
	if (board[y][x])return false;
	queue<pair<int,int>> q;
	q.push(pair<int,int>(y,x));
	int ret = 0;
	bool dp[10][10] = {false};
	while (!q.empty()) {
		pair<int, int> now = q.front();
		int nowy = now.first;
		int nowx = now.second;
		q.pop();
		REP(i, 4) {
			int nexty = nowy + vy[i];
			int nextx = nowx + vx[i];
			if (!ok(nexty, nextx))continue; // ???
			if (dp[nexty][nextx])continue; // ??????
			if (!board[nexty][nextx])continue; // ?????????
			ret++;
			dp[nexty][nextx] = true;
			q.push(pair<int, int>(nexty, nextx));
		}
	}
	if (ret == oCnt) return true;
	return false;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string A[10];
	oCnt = 0;
	REP(i, N) {
		cin >> A[i];
		REP(j, N) {
			if (A[i][j] == 'o') {
				board[i][j] = true;
				oCnt++;
			}
			else board[i][j] = false;
		}
	}
	REP(i, N) {
		REP(j, N) {
			if (check(i, j)) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
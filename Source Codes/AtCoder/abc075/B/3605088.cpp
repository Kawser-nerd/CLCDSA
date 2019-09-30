#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <deque>
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
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H,W;
	string S[60];
	cin >> H >> W;
	REP(i, H) cin >> S[i];
	int dx[] = { 1,1,0,-1,-1,-1, 0, 1 };
	int dy[] = { 0,1,1, 1, 0,-1,-1,-1 };
	REP(i, H) {
		REP(j, W) {
			if (S[i][j] == '.') {
				int cnt = 0;
				REP(k, 8) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (x >= 0 && x < H 
						&& y >= 0 && y <= W && S[x][y] == '#') {
						cnt++;
					}
					S[i][j] = '0' + cnt;
				}
			}
		}
	}
	REP(i, H) cout << S[i] << endl;
	return 0;
}
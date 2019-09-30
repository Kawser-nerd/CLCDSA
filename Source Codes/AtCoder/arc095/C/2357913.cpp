#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
#include <ctime>
#define rep(i, n) for (i = 0; i < n; i++)
using namespace std;
 
int h, w;
string s[12];
 
string reverse(string s) {
	int l = 0, r = s.length() - 1;
	while (l < r) {
		swap(s[l], s[r]);
		l++; r--;
	}
	return s;
}
 
void random_col() {
	int i, j;
	srand(101);
	rep(i, 100) rand();
	
	int tikan[12]; bool used[12] = {false};
	rep(i, w) {
		int t;
		do {
			t = rand() % w;
		} while (used[t]);
		used[t] = true;
		tikan[i] = t;
	}
	
	string tmp[12]; rep(i, h) rep(j, w) tmp[i] += s[i][tikan[j]];
	rep(i, h) s[i] = tmp[i];
}
 
void random_row() {
	int i, j;
	srand(151);
	rep(i, 100) rand();
	
	int tikan[12]; bool used[12] = {false};
	rep(i, h) {
		int t;
		do {
			t = rand() % h;
		} while (used[t]);
		used[t] = true;
		tikan[i] = t;
	}
	
	string tmp[12]; rep(i, h) tmp[i] = s[tikan[i]];
	rep(i, h) s[i] = tmp[i];
}

//????????
bool check(vector<int> perm) {
	int i, j;
	string t[12];
	rep(i, h) rep(j, w) t[i] += s[i][perm[j]];
	bool used[12] = {false};
	rep(i, h) {
		if (used[i]) continue;
		string tmp = reverse(t[i]);
		rep(j, h) if (j != i && !used[j] && tmp == t[j]) break;
		if (j < h) {
			used[i] = true; used[j] = true;
		}
	}
	
	int ngCnt = 0;
	rep(i, h) {
		if (used[i]) continue;
		if (h % 2 == 0) break;
		ngCnt++;
		if (ngCnt >= 2) break;
		if (reverse(t[i]) != t[i]) break;
	}
	return i == h;
}

//?? (ICPC2017-Asia-B??????)
int kumi[8][2];	//????????????
bool dfs(int rem, int noUse, int depth) {
	int i, j;
	vector<int> perm;
	
	if (w - depth * 2 == 1) {	//???????
		perm.resize(w);
		for (j = 0; j < depth; j++) {
			perm[j] = kumi[j][0];
			perm[w - 1 - j] = kumi[j][1];
		}
		perm[(w - 1) / 2] = noUse;
		//for (j = 0; j < perm.size(); j++) cout << perm[j] << " "; cout << endl;
		if (check(perm)) return true;
		return false;
	}
	if (w == depth * 2) {
		perm.resize(w);
		for (j = 0; j < depth; j++) {
			perm[j] = kumi[j][0];
			perm[w - 1 - j] = kumi[j][1];
		}
		if (check(perm)) return true;
		return false;
	}
	
	for (i = 0; i < w; i++) if (i != noUse && ((rem >> i) & 1)) break;
	for (j = i + 1; j < w; j++) {
		if (j != noUse && ((rem >> j) & 1)) {
			kumi[depth][0] = i;
			kumi[depth][1] = j;
			bool res = dfs(rem - (1 << i) - (1 << j), noUse, depth + 1);
			if (res) { return true; }
		}
	}
	return false;
}

signed main() {
	int i, j;
	
	cin >> h >> w;
	rep(i, h) cin >> s[i];
	
	//?????????????
	random_row();
	random_col();
	
	//??
	bool res = false;
	if (w % 2 == 0) res = dfs((1 << w) - 1, -1, 0);
	else {
		for (i = 0; i < w; i++) {
			res = dfs((1 << w) - 1, i, 0);
			if (res) break;
		}
	}
	
	if (res) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	return 0;
}
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <ctime>
#include <random>
#include <bitset>
#include <climits>
#include <cstring>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define ll long long
#define eps 1e-8
#define inf 1e6
using namespace std;

vector<int>v;
int n, A, B, C;

int dfs(int pos, int a, int b, int c) {
	if (pos == n) {
		if (min({ a,b,c }) > 0)
			return abs(a - A) + abs(b - B) + abs(c - C) - 30;
		else
			return inf;
	}
	int q = dfs(pos + 1, a, b, c), 
		w = dfs(pos + 1, a + v[pos], b, c) + 10,
		e = dfs(pos + 1, a, b + v[pos], c) + 10, 
		r = dfs(pos + 1, a, b, c + v[pos]) + 10;
	return min({ q,w,e,r });
}

int main() {
	speed;
	cin >> n >> A >> B >> C;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cout << dfs(0, 0, 0, 0);
}
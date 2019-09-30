#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const LL INF = 1e18;
const int MAXN = 111111 * 2;
int n, E;
LL f[MAXN], minf[MAXN], x[MAXN], T, tr[MAXN << 2];

inline int get_node(int l, int r) {
	return l + r | l != r;
}

inline void build_tree(int l, int r) {
	int k = get_node(l, r);
	tr[k] = INF;
	if (l == r) return;
	int mid = l + r >> 1;
	build_tree(l, mid);
	build_tree(mid + 1, r);
}

inline void add(int l, int r, int x, LL val) {
	int k = get_node(l, r);
	if (l == r) {
		tr[k] = val;
		return;
	}
	int mid = l + r >> 1;
	if (x > mid) {
		add(mid + 1, r, x, val);
	} else {
		add(l, mid, x, val);
	}
	tr[k] = min(tr[get_node(l, mid)], tr[get_node(mid + 1, r)]);
}

inline LL query(int l, int r, int a, int b) {
	int k = get_node(l, r);
	if (l == a && r == b) {
		return tr[k];
	}
	int mid = l + r >> 1;
	if (a > mid) return query(mid + 1, r, a, b);
	if (b <= mid) return query(l, mid, a, b);
	return min(query(l, mid, a, mid), query(mid + 1, r, mid + 1, b));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> E >> T;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	
	x[0] = 0;
	x[n + 1] = E;
	f[0] = 0;
	minf[0] = f[0] - x[0] - x[1] * 2;
	build_tree(0 + 1, n + 1);
	add(0 + 1, n + 1, 0 + 1, f[0] - x[0]);
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + x[i] - x[i - 1] + T;
		/*for (int j = 0; j < i; ++j) {
			LL temp;
			if (T > (x[i] - x[j + 1]) * 2) {
				temp = f[j] + x[i] - x[j] + T;
			} else {
				temp = f[j] + x[i] - x[j] + (x[i] - x[j + 1]) * 2;
			}
			f[i] = min(f[i], temp);
		}*/
		int left = 0, right = i - 1;
		while (left < right) {
			int mid = left + right >> 1;
			if (T > (x[i] - x[mid + 1]) * 2) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		f[i] = min(f[i], query(0 + 1, n + 1, left + 1, i - 1 + 1) + x[i] + T);
		if (left > 0) {
			f[i] = min(f[i], minf[left - 1] + x[i] * 3);
		}
		minf[i] = min(minf[i - 1], f[i] - x[i] - x[i + 1] * 2);
		add(0 + 1, n + 1, i + 1, f[i] - x[i]);
	}
	cout << f[n] + x[n + 1] - x[n] << endl;
} ./Main.cpp:17:15: warning: | has lower precedence than !=; != will be evaluated first [-Wparentheses]
        return l + r | l != r;
                     ^~~~~~~~
./Main.cpp:17:15: note: place parentheses around the '!=' expression to silence this warning
        return l + r | l != r;
                     ^
                       (     )
./Main.cpp:17:15: note: place parentheses around the | expression to evaluate it first
        return l + r | l != r;
                     ^
               (        )
./Main.cpp:24:14: warning: operator '>>' has lower precedence than '+'; '+' will be evaluated first [-Wshift-op-parentheses]
        int mid = l + r >> 1;
                  ~~^~~ ~~
./Main.cpp:24:14: note: place parentheses around the '+' expression to silence this warning
        int mid = l + r >> 1;
                    ^
                  (    )
./Main.cpp:35:14: warning: operator '>>' has lower precedence than '+'; '+' will be evaluated first [-Wshift-op-parentheses]
        int mid = l + r >> 1;
          ...
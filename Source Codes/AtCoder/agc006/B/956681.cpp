#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

#define dfor(i,a,b) for(int i=(a);i<(b);++i)
#define drfor(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define drep(i,n) dfor(i,0,n)
#define drrep(i,n) drfor (i,n,0)
#define dump(x)  cout << #x << " = " << (x) << endl;

const double EPS = 1e-10;

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	if ((x == 1) || (x == n * 2 - 1)) {
		cout << "No";
		return 0;
	}
	else {
		cout << "Yes\n";
	}
	if (x == n) {
		drep(i, n * 2 - 1) {
			cout << i+1 << "\n";
		}
		return 0;
	}
	if (x > n) {
		drep(i, n - 1) {
			cout << i+1 << "\n";
		}
		drfor(i, n,x + 2) {
			cout << i << "\n";
		}
		drfor(i, x + 2,2*n) {
			cout << i << "\n";
		}
	}
	else {
		x = 2 * n - x;
		drep(i, n - 1) {
			cout << 2*n-i-1 << "\n";
		}
		drfor(i, n,x+2) {
			cout << 2*n-i << "\n";
		}
		drfor(i, x + 2,n*2) {
			cout << 2*n-i << "\n";
		}
	}
	return 0;
}
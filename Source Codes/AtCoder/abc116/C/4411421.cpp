#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
	int n;
	vector<int> node;
	SegTree(vector<int> v) {
		int sz = v.size();
		for(n = 1; n < sz; n <<= 1);
		node.resize(2 * n - 1, INT_MAX);
		//????v??????
		for(int i = 0; i < sz; i++) node[i + n - 1] = v[i];

		//???????
		for(int i = n - 2; i >= 0; i--) node[i] = min(node[2*i + 1], node[2*i + 2]);
	}

	void update(int p, int v) {
		p += n - 1;
		node[p] = v;
		while(p > 0) {
			p = (p - 1) / 2; //?????1???2????????
			node[p] = min(node[2*p + 1], node[2*p + 2]);
		}
	}

	void sub(int p, int v) {
		int q = p + n - 1;
		v = node[q] - v;
		update(p, v);
	}

	int getmin(int l, int r, int k=0, int nl=0, int nr= -1) {
		if(nr == -1) nr = n;
		if(nr <= l || nl >= r) return INT_MAX;
		if(l <= nl && nr <= r) return node[k];
		int vl = getmin(l, r, 2 * k + 1, nl, (nl + nr) / 2);
		int vr = getmin(l, r, 2 * k + 2, (nl + nr) / 2, nr);

		return min(vl, vr);
	}

	int getmax(int l, int r, int k=0, int nl=0, int nr= -1) {
		if(nr == -1) nr = n;
		if(nr <= l || nl >= r) return INT_MIN;
		if(l <= nl && nr <= r) return node[k];
		int vl = getmax(l, r, 2 * k + 1, nl, (nl + nr) / 2);
		int vr = getmax(l, r, 2 * k + 2, (nl + nr) / 2, nr);

		return max(vl, vr);
	}

	void print() {
		for(int i = 0; i < n; i++) {
			cout << node[i + n - 1] << " ";
		}
		cout << endl;
	}

	void print_all() {
		for(auto x: node) cout << x << " ";
		cout << endl;
	}
};

int main() {
	int N;
	cin >> N;
	vector<int> h(N);
	for(auto &x: h) cin >> x;
	SegTree sg(h);

	int out = 0;
	for(int r = N; r > 0; r--) {
		for(int i = 0; i <= N - r; i++) {
			int n = sg.getmin(i, r + i);
			if(n == 0) continue;
			for(int j = i; j < r + i; j++) {
				sg.sub(j, n);
			}
			out += n;
		}
	}

	cout << out << endl;
}
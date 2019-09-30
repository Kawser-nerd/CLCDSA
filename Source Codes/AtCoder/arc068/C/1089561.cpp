#ifndef ___Class_RangeTree
#define ___Class_RangeTree

// ------ Includes ------ //
#include <limits>
#include <vector>
#include <algorithm>

template<typename Type> class RangeTree {
private:
	int size_;
	std::vector<std::vector<Type> > dat;
	std::vector<std::vector<int> > vl;
	inline int query_(int a, int b, Type x, int k, int l, int r, int e) {
		// Find range [a, b) : value < x : Now k-th node and the range is [l, r) and e integers below x in the range
		if (r <= a || b <= l || e == 0) return 0;
		if (a <= l && r <= b) return e;
		int lc = query_(a, b, x, k << 1, l, (l + r) >> 1, vl[k][e - 1]);
		int rc = query_(a, b, x, k << 1 | 1, (l + r) >> 1, r, e - vl[k][e - 1]);
		return lc + rc;
	}
public:
	RangeTree() : size_(0), dat(std::vector<Type>()) {};
	template<class T>
	RangeTree(T begin_, T end_) {
		int n = (end_ - begin_);
		for (size_ = 1; size_ < n; size_ <<= 1);
		dat.resize(size_ << 1);
		vl.resize(size_);
		for (int i = 0; i < n; i++) dat[i + size_].push_back(*(begin_ + i));
		for (int i = size_ - 1; i > 0; i--) {
			dat[i].resize(dat[i << 1].size() + dat[i << 1 | 1].size());
			vl[i].resize(dat[i].size());
			int cl = 0;
			for (int j = 0; j < dat[i].size(); j++) {
				if (j - cl == dat[i << 1 | 1].size() || (cl != dat[i << 1].size() && dat[i << 1][cl] < dat[i << 1 | 1][j - cl])) dat[i][j] = dat[i << 1][cl++];
				else dat[i][j] = dat[i << 1 | 1][j - cl];
				vl[i][j] = cl;
			}
		}
	}
	inline int size() { return size_; }
	inline int query(int l, int r, Type x) {
		// Find range [a, b) : value < x
		int ptr = lower_bound(dat[1].begin(), dat[1].end(), x) - dat[1].begin();
		return query_(l, r, x, 1, 0, size_, ptr);
	}
};

#endif

#include <cstdio>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;
struct query {
	int l, r;
};
bool compare(const query& q1, const query& q2) {
	return q1.r < q2.r;
}
// rc[k] : number of q[i].r < k
int N, M, dat[300009], rc[300009], ret[300009]; query q[300009];
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d%d", &q[i].l, &q[i].r);
	sort(q, q + N, compare);
	for (int i = 0; i < N; i++) dat[i] = q[i].l;
	int ptr = 0;
	for (int i = 1; i <= M; i++) {
		while (ptr < N && q[ptr].r < i) ptr++;
		rc[i] = ptr;
	}
	RangeTree<int> Q(dat, dat + N);
	for (int i = 1; i <= M; i++) {
		for (int j = i; j <= M; j += i) {
			ret[i] += Q.query(rc[j], N, j + 1);
			ret[i] -= Q.query(rc[j], N, j - i + 1);
		}
	}
	for (int i = 1; i <= M; i++) printf("%d\n", ret[i]);
	return 0;
}
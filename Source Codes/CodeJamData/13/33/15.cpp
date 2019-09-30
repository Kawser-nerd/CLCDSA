#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <vector>
using namespace std;

struct Attack {
	int day;
	int l, r;
	int pow;
	Attack(int day, int l, int r, int pow) :
			day(day), l(l), r(r), pow(pow) {
	}

	bool operator<(const Attack&o) const {
		return day < o.day;
	}
};

vector<Attack> attacks;

typedef int T;
struct Index: public vector<T> {
	void doit() {
		sort(begin(), end());
		erase(unique(begin(), end()), end());
	}
	int get(T x) {
		return lower_bound(begin(), end(), x) - begin();
	}
};

Index idx;

void addTribe() {
	int d, n, w, e, s, dd, dp, ds;
	cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
	//d,w,e,s
	for (int i = 0; i < n; ++i) {
		attacks.push_back(Attack(d, w, e, s));
		d += dd;
		w += dp, e += dp;
		s += ds;
	}
}

const int INF = ~0U >> 1;

struct Tree {
	Tree*pl, *pr;
	int l, r, mi, upd;

	void update() {
		mi = min(pl->mi, pr->mi);
	}

	void apply(int up) {
		upd = max(upd, up);
		mi = max(mi, up);
		//<up -> up
	}

	void relax() {
		pl->apply(upd);
		pr->apply(upd);
	}

	Tree(int l, int r) :
			l(l), r(r) {
		mi = 0;
		upd = 0;
		if (l + 1 == r) {
			pl = pr = 0;
			return;
		}
		pl = new Tree(l, l + r >> 1);
		pr = new Tree(l + r >> 1, r);
		update();
	}

	void change(int L, int R, int up) {
		if (L <= l && R >= r) {
			apply(up);
			return;
		}
		if (L >= r || l >= R)
			return;
		relax();
		pl->change(L, R, up);
		pr->change(L, R, up);
		update();
	}

	int query(int L, int R) {
		if (L <= l && R >= r) {
			return mi;
		}
		if (L >= r || l >= R)
			return INF;
		relax();
		return min(pl->query(L, R), pr->query(L, R));
	}
}*rt;

void recyc(Tree*a) {

}

int solve() {
	idx.clear();
	for (vector<Attack>::iterator e = attacks.begin(); e != attacks.end();
			++e) {
		idx.push_back(e->l);
		idx.push_back(e->r);
	}
	idx.doit();

	rt = new Tree(0, idx.size());

	sort(attacks.begin(), attacks.end());

	for (vector<Attack>::iterator e = attacks.begin(); e != attacks.end();
			++e) {
		e->l = idx.get(e->l);
		e->r = idx.get(e->r);
	}

	int cnt = 0;

	for (int i = 0, j; i < attacks.size(); i = j) {
		for (j = i; j < attacks.size() && attacks[i].day == attacks[j].day; ++j)
			;
		//[i,j)
		for (int k = i; k < j; ++k) {
			int mi = rt->query(attacks[k].l, attacks[k].r);
			if (mi < attacks[k].pow) {
				++cnt;
			}
		}

		for (int k = i; k < j; ++k) {
			rt->change(attacks[k].l, attacks[k].r, attacks[k].pow);
		}
	}
	return cnt;
}

int work() {
	attacks.clear();

	int n;
	cin >> n;
	while (n--) {
		addTribe();
	}

	return solve();
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		cout << work() << endl;
	}
}

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define SIZE(v) ((int)(v).size())

#define BEGIN(v) ((v).begin())
#define END(v) ((v).end())
#define ALL(v) BEGIN(v),END(v)
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v);(v).erase(unique(ALL(v)),END(v))
#define INDEX(v,x) lower_bound(ALL(v),(x))-BEGIN(v)

#define FOR(i,l,r) for(int i=(l);i<(r);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)

const int MAXD = 1000000;

struct Segment {
	int lowest, fix;

	Segment() {}

	Segment(int lowest) : lowest(lowest), fix(0) {}

	Segment(int lowest, int fix) : lowest(lowest), fix(fix) {}

	int getLowest() const {
		return max(lowest, fix);
	}

	void update() {
		lowest = max(lowest, fix);
	}

	Segment operator + (const Segment &rhs) const {
		return Segment(min(getLowest(), rhs.getLowest()));
	}
};

struct SegmentTree {
	int n;
	vector<Segment> seg;
	
	static int LEFT(int idx) { return idx << 1; }
	static int RIGHT(int idx) { return (idx << 1) | 1; }

	void _build(int idx, int lower, int upper) {
		if (lower == upper) {
			seg[idx] = Segment(0);
			return ;
		}
		int middle = (lower + upper) >> 1;
		_build(LEFT(idx), lower, middle);
		_build(RIGHT(idx), middle + 1, upper);
		seg[idx] = seg[LEFT(idx)] + seg[RIGHT(idx)];
	}

	void init(int n) {
		this->n = n;
		seg = vector<Segment>(n << 2);
		_build(1, 0, n - 1);
	}

	void pushDown(int idx) {
		seg[LEFT(idx)].fix = max(seg[LEFT(idx)].fix, seg[idx].fix);
		seg[RIGHT(idx)].fix = max(seg[RIGHT(idx)].fix, seg[idx].fix);
		seg[idx].lowest = max(seg[idx].lowest, seg[idx].fix);
		seg[idx].fix = 0;
	}

	int l, r, v;

	void _modify(int idx, int lower, int upper) {
		if (l <= lower && upper <= r) {
			seg[idx].fix = max(seg[idx].fix, v);
			return ;
		}
		pushDown(idx);
		int middle = (lower + upper) >> 1;
		if (r <= middle) {
			_modify(LEFT(idx), lower, middle);
		} else if (middle < l) {
			_modify(RIGHT(idx), middle + 1, upper);
		} else {
			_modify(LEFT(idx), lower, middle);
			_modify(RIGHT(idx), middle + 1, upper);
		}
		seg[idx] = seg[LEFT(idx)] + seg[RIGHT(idx)];
	}

	void modify(int l, int r, int v) {
		this->l = l;
		this->r = r;
		this->v = v;
		_modify(1, 0, n - 1);
	}

	Segment _calc(int idx, int lower, int upper) {
		if (l <= lower && upper <= r) {
			seg[idx].update();
			return seg[idx];
		}
		pushDown(idx);
		int middle = (lower + upper) >> 1;
		Segment res;
		if (r <= middle) {
			res = _calc(LEFT(idx), lower, middle);
		} else if (middle < l) {
			res = _calc(RIGHT(idx), middle + 1, upper);
		} else {
			res = _calc(LEFT(idx), lower, middle) + _calc(RIGHT(idx), middle + 1, upper);
		}
		seg[idx] = seg[LEFT(idx)] + seg[RIGHT(idx)];
		return res;
	}

	Segment calc(int l, int r) {
		this->l = l;
		this->r = r;
		return _calc(1, 0, n - 1);
	}
};

struct Attack {
	int w, e, s;

	Attack() {}

	Attack(int w, int e, int s) : w(w), e(e), s(s) {}
};

int N;
vector<Attack> attacks[MAXD];
vector<int> DIS;
SegmentTree smt;

void init() {
	DIS.clear();
	FOR(i, 0, MAXD) attacks[i].clear();
}

int main() {
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 1; taskIdx <= taskNumber; taskIdx++) {
		init();
		scanf("%d", &N);
		FOR(_, 0, N) {
			int d, n, w, e, s, deltaD, deltaP, deltaS;
			scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &deltaD, &deltaP, &deltaS);
			for (int i = 0; i < n; i++) {
				DIS.push_back(w - 1);
				DIS.push_back(w);
				DIS.push_back(e - 1);
				DIS.push_back(e);
				attacks[d].push_back(Attack(w, e, s));
				w += deltaP; e += deltaP;
				d += deltaD;
				s += deltaS;
			}
		}
		UNIQUE(DIS);
		smt.init(SIZE(DIS));
		int res = 0;
		FOR(day, 0, MAXD) {
			FOREACH(it, attacks[day]) {
				int w = INDEX(DIS, it->w), e = INDEX(DIS, it->e) - 1;
				res += smt.calc(w, e).lowest < it->s;
			}
			FOREACH(it, attacks[day]) {
				int w = INDEX(DIS, it->w), e = INDEX(DIS, it->e) - 1;
				smt.modify(w, e, it->s);
			}
		}
		printf("Case #%d: %d\n", taskIdx, res);
	}
	return 0;
}

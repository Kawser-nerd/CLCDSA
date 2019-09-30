#include <algorithm>
#include <cassert>
#include <cstdio>
#include <deque>
#include <vector>
#include <set>
using namespace std;
int n;
typedef long long ll;
struct Elt {
	ll e;
	ll m;
	Elt(ll ee, ll mm): e(ee), m(mm) {}
	bool operator<(const Elt & o) const {
		// if (e != o.e) return e < o.e;
		// return m < o.m;
		return e < o.e;
	}
};

deque<Elt> elements, newElements;
// vector<deque<Elt> > history;
deque<Elt> kills;
vector<ll> diffs;

void shadow(set<ll> & s, ll diff) {
	set<ll> copy = s;
	for (ll x : copy) {
		s.insert(x + diff);
	}
}

ll es[10008];
ll fs[10008];
void tc() {
	scanf("%d", &n);
	newElements.clear();
	elements.clear();
	// history.clear();
	kills.clear();
	diffs.clear();
	for (int i = 0; i < n; ++i){ scanf("%lld", &es[i]); }
	for (int i = 0; i < n; ++i){
		scanf("%lld", &fs[i]);
		elements.push_back(Elt(es[i], fs[i]));
	}
	Elt ef = elements.front();
	int zeros = 0;
	while (ef.m > 1) {
		assert((ef.m & 1) == 0);
		ef.m >>= 1;
		zeros++;
	}
	for (Elt& elt : elements) {
		assert((elt.m & ((1 << zeros) - 1)) == 0);
		elt.m >>= zeros;
	}
	// history.push_back(elements);
	while (elements.size() > 1) {
		Elt e1 = elements.front();
		assert(e1.m == 1);
		elements.pop_front();
		Elt e2 = elements.front();
		if (e2.m == 1) {
			elements.pop_front();
		} else {
			elements.front().m--;
		}
		newElements.push_back(e1);
		ll d = e2.e - e1.e;
		diffs.push_back(d);
		while (elements.size()) {
			if (kills.size() && elements.front().e == kills.front().e) {
				elements.front().m -= kills.front().m;
				assert(elements.front().m >= 0);
				if (elements.front().m == 0) {
					elements.pop_front();
				}
				kills.pop_front();
			} else {
				Elt e = elements.front();
				elements.pop_front();
				newElements.push_back(e);
				kills.push_back(Elt(e.e + d, e.m));
			}
		}
		assert(kills.size() == 0);
		elements.swap(newElements);
	}

	assert(elements[0].m == 1);
	ll low = elements[0].e;
	assert(low <= 0);
	low = -low;

	ll negacc = 0;
	for (size_t di = diffs.size(); di --> 0; ) {
		// can it be negative?
		// i.e. can we reach (low - negacc) from the smaller ones?
		// printf("(di = %lu; diff = %lld)\n", di, diffs[di]);
		if (negacc + diffs[di] > low) {
			// nope
			continue;
		}
		ll remain = low - negacc - diffs[di];
		set<ll> space;
		space.insert(0);
		for (size_t dj = di; dj --> 0; ) {
			shadow(space, diffs[dj]);
		}
		if (space.count(remain)) {
			// yeah!
			negacc += diffs[di];
			diffs[di] = -diffs[di];
		}
	}

	for (int i = 0; i < zeros; i++) {
		diffs.push_back(0);
	}
	sort(diffs.begin(), diffs.end());

	bool first = true;
	for (ll d : diffs) {
		if (!first) printf(" ");
		first = false;
		printf("%lld", d);
	}
	printf("\n");
}
int main() {
    int tcn; scanf("%d", &tcn);
    for (int tci = 1; tci <= tcn; ++tci) {
        printf("Case #%d: ", tci);
        tc();
    }
    return 0;
}


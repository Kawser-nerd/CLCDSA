#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;

const int LIMIT = 1000000;

typedef pair<int, int> PII;

class Checker {
public:
	vector<PII> birds, others;
	int fmin, fmax, smin, smax;
	int sb, so;

	Checker(const set<PII> & birds, const set<PII> & others) {
		this->birds.assign(birds.begin(), birds.end());
		this->others.assign(others.begin(), others.end());
		init();
	}

	void init() {
		sb = birds.size();
		so = others.size();
		fmin = fmax = birds[0].first;
		smin = smax = birds[0].second;
		for (int i = 0; i < sb; i++) {
			fmin = min(fmin, birds[i].first);
			fmax = max(fmax, birds[i].first);
			smin = min(smin, birds[i].second);
			smax = max(smax, birds[i].second);
		}
	}

	inline bool canBird(const PII & p) const {
		if (fmin <= p.first && p.first <= fmax && smin <= p.second && p.second <= smax) {
			return true;
		}
		int cfmin = min(fmin, p.first);
		int cfmax = max(fmax, p.first);
		int csmin = min(smin, p.second);
		int csmax = max(smax, p.second);
		for (int i = 0; i < so; i++) {
			if (cfmin <= others[i].first && others[i].first <= cfmax && csmin <= others[i].second && others[i].second <= csmax) {
				return false;
			}
		}
		return true;
	}

	inline bool canNotBird(const PII & p) const {
		return !(fmin <= p.first && p.first <= fmax && smin <= p.second && p.second <= smax);
	}
};

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int n, m;
		scanf("%d%d", &n, &m);
		set<PII> birds, others;
		for (int i = 0; i < n; i++) {
			int f, s;
			char str[16];
			scanf("%d%d", &f, &s);
			gets(str);
			if (str[1] == 'B') {
				birds.insert(PII(f, s));
			} else {
				others.insert(PII(f, s));
			}
		}
		scanf("%d", &m);
		printf("Case #%d:\n", caseIndex);
		if (birds.empty()) {
			while (m-- > 0) {
				int f, s;
				scanf("%d%d", &f, &s);
				if (others.find(PII(f, s)) == others.end()) {
					puts("UNKNOWN");
				} else {
					puts("NOT BIRD");
				}
			}
		} else {
			Checker checker(birds, others);
			while (m-- > 0) {
				int f, s;
				scanf("%d%d", &f, &s);
				PII p(f, s);
				if (checker.canBird(p)) {
					if (checker.canNotBird(p)) {
						puts("UNKNOWN");
					} else {
						puts("BIRD");
					}
				} else {
					puts("NOT BIRD");
				}
			}
		}
		
		
	}

	return 0;
}

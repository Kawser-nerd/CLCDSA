#include<queue>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

struct BySecond {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) const {
	return x.second < y.second;
    }
} bySecond;

int N, Q;
pair<int, int> AB[100011];
int C[100011];
pair<int, int> DE[100011];

int cnt[100011];
int add[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", &AB[i].first, &AB[i].second);
    REP (i, N+1) scanf("%d", C+i);
    scanf("%d", &Q);
    REP (i, Q) scanf("%d%d", &DE[i].first, &DE[i].second);

    sort(C, C+N+1);

    REP (i, N) {
	AB[i].first = lower_bound(C, C+N+1, AB[i].first) - C;
	AB[i].second = lower_bound(C, C+N+1, AB[i].second) - C;
	amin(AB[i].second, AB[i].first);
    }
    REP (i, Q) {
	DE[i].first = lower_bound(C, C+N+1, DE[i].first) - C;
	DE[i].second = lower_bound(C, C+N+1, DE[i].second) - C;
	amin(DE[i].second, DE[i].first);
    }

    sort(AB, AB+N);

    int pos = 0;
    REP (i, N+1) {
	cnt[i+1] = cnt[i];
	while (pos < N && AB[pos].first == i) {
	    cnt[i+1]++;
	    pos++;
	}
    }
    REP (i, N+2) cnt[i] -= i;

    priority_queue<pair<int, int> > pq;
    vector<pair<int, int> > R;
    sort(AB, AB+N, bySecond);
    pos = 0;
    REP (i, N+1) {
	add[i+1] += add[i];
	while (pos < N && AB[pos].second == i) {
	    pq.push(AB[pos]);
	    pos++;
	}

	while (cnt[i+1]+add[i+1] < 0 && !pq.empty()) {
	    pair<int, int> p = pq.top();
	    pq.pop();
	    if (i < p.first) {
		R.emplace_back(i+1, p.first+1);
		add[i+1]++;
		add[p.first+1]--;
	    }
	}
    }
    REP (i, N+2) cnt[i] += add[i];

    bool bad = false;
    VI negs;
    REP (i, N+2) {
	if (cnt[i] <= -2) {
	    bad = true;
	} else if (cnt[i] <= -1) {
	    negs.push_back(i);
	}
    }

    if (bad) {
	REP (i, Q) puts("-1");
    } else {
	int left = N+2;
	sort(R.begin(), R.end());
	VI Z;
	for (int i=R.size(); i--;) {
	    int k = lower_bound(negs.begin(), negs.end(), R[i].first) - negs.begin();
	    if (k < (int)negs.size() && negs[k] < R[i].second) continue;

	    if (R[i].second <= left) {
		Z.push_back(R[i].first);
		left = R[i].first;
	    }
	}
	reverse(Z.begin(), Z.end());
	REP (i, Q) {
	    int d = DE[i].first;
	    int e = DE[i].second;

	    int ans = -1;
	    if (negs[0] <= e) {
		ans = -1;
	    } else {
		ans = 0;
		if (d < negs[0]) {
		    int len = Z.end() - lower_bound(Z.begin(), Z.end(), d+1);
		    amax(ans, N - (int)R.size() + len + 1);
		}

		{
		    int len = Z.end() - lower_bound(Z.begin(), Z.end(), e+1);
		    amax(ans, N - (int)R.size() + len);
		}
	    }
	    printf("%d\n", ans);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}
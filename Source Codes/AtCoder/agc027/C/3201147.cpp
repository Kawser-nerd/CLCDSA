#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, M;
VI G[200011];
char S[200011];
int D[200011][2];
bool del[200011];

void MAIN() {
    scanf("%d%d%s", &N, &M, S);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    REP (i, N) {
	EACH (e, G[i]) D[i][S[*e]-'A']++;
    }

    VI st;
    REP (i, N) if (D[i][0] == 0 || D[i][1] == 0) {
	st.push_back(i);
	del[i] = true;
    }
    while (!st.empty()) {
	int v = st.back(); st.pop_back();
	EACH (e, G[v]) if (!del[*e]) {
	    D[*e][S[v]-'A']--;
	    if (D[*e][S[v]-'A'] == 0) {
		st.push_back(*e);
		del[*e] = true;
	    }
	}
    }

    int cnt = 0;
    REP (i, N) if (!del[i]) cnt++;
    if (cnt >= 2) puts("Yes");
    else puts("No");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}
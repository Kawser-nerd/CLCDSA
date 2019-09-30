#include <string>
#include <cstring>
#include <vector>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define FOR(a,b,c) for(int a=(b); a<=(c); ++a)
#define INIT(a, v) __typeof(v) a = (v)
#define FOREACH(a, v) for (INIT(a, (v).begin()); a!=(v).end(); ++a)
 
template<class T>
inline int size(const T&t){return t.size();}
 
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long LL;

#define INF 1000000000
#define PB push_back
#define MP make_pair
 
//////////////////////////////////////////

int C[80], S[80], T[80];
int R, L;
int best;

int zos, bylo_tur, score;
int cur;
int reka[85], iler;

void graj(int nr) {
    int k = reka[nr];
    reka[nr] = reka[iler-1];
    --iler;
    ++bylo_tur;
    zos += T[k]-1;
    score += S[k];
    REP(a, C[k])
        if (cur<R+L)
            reka[iler++] = cur++;
}

void probuj(int ile1, int ile2) {
    bylo_tur = score = 0;
    zos = 1;
    cur = R;
    iler = R;
    REP(a, R)
        reka[a] = a;
    while (iler && zos) {
        bool sa2 = false;
        bool sa1 = false;
        int minc, bests, bestnr;
        REP(a, iler) {
            if (T[reka[a]]) {
                graj(a);
                goto dalej;
            }
            if (C[reka[a]]==1)
                sa1 = true;
            if (C[reka[a]]==2)
                sa2 = true;
        }
        minc = (bylo_tur<ile2 && sa2) ? 2 : (bylo_tur<ile1 && (sa1 || sa2)) ? 1 : 0;
        bests = -1;
        REP(a, iler)
            if (C[reka[a]]>=minc && S[reka[a]]>bests) {
                bests = S[reka[a]];
                bestnr = a;
            }
        graj(bestnr);
        dalej:;
    }
    best = max(best, score);
}

int main() {
    int TT;
    scanf("%d", &TT);
    REP(tt, TT) {
        scanf("%d", &R);
        REP(a, R)
            scanf("%d%d%d", &C[a], &S[a], &T[a]);
        scanf("%d", &L);
        REP(a, L)
            scanf("%d%d%d", &C[R+a], &S[R+a], &T[R+a]);
        best = 0;
        REP(ile1, R+L+1)
            REP(ile2, ile1+1)
                probuj(ile1, ile2);
        printf("Case #%d: %d\n", (tt+1), best);
    }
}



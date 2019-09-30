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

int N, K;

string slowa[10000];
int kara2[10000];
int gdzie_litery[10000][26];
pii tab[10000];
int gr_od[10005], gr_do[10005], ileg, kara[10005];
int ma_litery[10005];

void licz_litery(int nr) {
    ma_litery[nr] = 0;
    FOR(x, gr_od[nr], gr_do[nr]-1) {
        int a = tab[x].second;
        REP(b, size(slowa[a]))
            ma_litery[nr] |= 1<<(slowa[a][b]-'a');
    }
}

void dziel_gr(int nr, int kara_za) {
    int stare_ileg = ileg;
    sort(tab+gr_od[nr], tab+gr_do[nr]);
    int pocz = gr_od[nr];
    FOR(x, gr_od[nr], gr_do[nr]-1)
        if (x==gr_do[nr]-1 || tab[x].first!=tab[x+1].first) {
            gr_od[ileg] = pocz;
            pocz = gr_do[ileg] = x+1;
            kara[ileg] = kara[nr]+(kara_za==tab[x].first);
            ++ileg;
        }
    --ileg;
    gr_od[nr] = gr_od[ileg];
    gr_do[nr] = gr_do[ileg];
    kara[nr] = kara[ileg];
    if (ileg>stare_ileg) {
        licz_litery(nr);
        FOR(x, stare_ileg, ileg-1)
            licz_litery(x);
    }
}

void przygotuj() {
    REP(a, N) {
        tab[a].first = size(slowa[a]);
        tab[a].second = a;
    }
    ileg = 1;
    kara[0] = gr_od[0] = 0;
    gr_do[0] = N;
    dziel_gr(0, -1);
    if (ileg==1)
        licz_litery(0);
}

void check(char *buf) {
    REP(y, 26) {
        int stare_ileg = ileg;
        int lit = *buf-'a';
        REP(nrg, stare_ileg) {
            if (!(ma_litery[nrg]&(1<<lit)))
                continue;
            FOR(x, gr_od[nrg], gr_do[nrg]-1)
                tab[x].first = gdzie_litery[tab[x].second][lit];
            dziel_gr(nrg, 0);
        }
        ++buf;
    }
    int best = -1;
    REP(nrg, ileg) {
        FOR(x, gr_od[nrg], gr_do[nrg]-1)
            kara2[tab[x].second] = kara[nrg];
        best = max(best, kara[nrg]);
    }
    REP(a, N)
        if (kara2[a]==best) {
            printf(" %s", slowa[a].c_str());
            return;
        }
}

int main() {
    int TT;
    scanf("%d", &TT);
    REP(tt, TT) {
        scanf("%d%d", &N, &K);
        char buf[30];
        REP(a, N) {
            scanf("%s", buf);
            slowa[a] = buf;
            REP(l, 26)
                gdzie_litery[a][l] = 0;
            REP(b, size(slowa[a]))
                gdzie_litery[a][slowa[a][b]-'a'] |= 1<<b;
        }
        printf("Case #%d:", (tt+1));
        REP(a, K) {
            scanf("%s", buf);
            przygotuj();
            check(buf);
        }
        printf("\n");
    }
}



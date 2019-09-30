#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

#define VV vector
#define PB push_back
#define ll long long
#define ld long double
#define REP(i,n) FOR(i,0,(n)-1)
#define FOR(i,a,b) for(int i = (a);i<=(b);++i)
#define FORD(i,a,b) for(int i = (a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SS(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define VI VV<int>
#define VS VV<string>
int COND = 1;
#define DB(x) { if (COND > 0) { COND--; REP (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

int N, M;

char A[41][41];
#define PII pair<int, int>
#define X first
#define Y second


int DST[41][41][41][41];
PII PR[41][41][41][41];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

PII Q[41 * 41] ; int SS, EE;
void BFS(int XX[41][41], PII PP[41][41], int i, int j) {
    SS = EE = 0;
    XX[i][j] = 0; Q[EE++] = PII(i, j);

    PP[i][j] = PII(-1, -1); 
    while (SS < EE) {
        PII top = Q[SS++];
        REP (d, 4) {
            int nx = top.X + dx[d];
            int ny = top.Y + dy[d];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && XX[nx][ny] == -1 && A[nx][ny] != '.') {
                XX[nx][ny] = XX[top.X][top.Y] + 1;
                    ; Q[EE++] = PII(nx, ny);
                PP[nx][ny] = PII(top.X, top.Y);
            }
        }
    }
}

bool VSS[41][41];

int DDD[41][41];
PII KTO[41][41];
int VIS[41][41] = {};
int ret;

void add(int i, int j) {
    PII kto = KTO[i][j];

    PII p = PII(i, j);;
    DB(KTO[i][j].X<<" "<<KTO[i][j].Y);
    while (p.X != -1) {
        if (!VIS[p.X][p.Y])
            ret += DST[kto.X][kto.Y][p.X][p.Y];
        VIS[p.X][p.Y] = 1;
        DB(DST[kto.X][kto.Y][p.X][p.Y]);
        p = PR[kto.X][kto.Y][p.X][p.Y];
    }
    VIS[p.X][p.Y] = 1;

    FOR (a, 1, N) FOR (b, 1, M) if (DDD[a][b] > DST[i][j][a][b]) {
        DDD[a][b] = DST[i][j][a][b];
        KTO[a][b] = PII(i, j);
    }
}

int solve() {
    CLR(DDD, 0x7f);
    CLR(VIS, 0);
    CLR(DST, -1);
    CLR(A, 0);
    CLR(VSS, 0);
    cin >> N >> M;
    VV <PII> TR;
    FOR (i, 1, N) FOR (j, 1, M) cin >> A[i][j];
    FOR (i, 1, N) FOR (j, 1, M) if (A[i][j] == 'T') {
        TR.PB(PII(i,j));
        BFS(DST[i][j], PR[i][j], i, j);
    }
    int ile = 1;
    VSS[1][1] = 1;
    KTO[1][1] = PII(1, 1);
    ret = 0;
    add(1,1); 
    DB(ret);
    while (ile < (int)TR.size()) {
        PII cand(1,1); int cur = (int)1e9;
        
        FOR (i, 1, N) FOR (j, 1, M) if (A[i][j] == 'T' && !VSS[i][j]) {
            if (cur > DDD[i][j]) {
                cand = PII(i, j);
                cur = DDD[i][j];
            }
        }
        VSS[cand.X][cand.Y] = 1;
        DB(cand.X<<" "<<cand.Y);
        add(cand.X, cand.Y);
        DB(ret);
        ile++;
    }

    /*
    if (TR.size() == 1) {
        FOR (i, 1, N) FOR (j, 1, M) 
            if (A[i][j] != '.') 
                ret += DST[1][1][i][j];
    }
    else {
        PII p = TR[1];;
        while (p != PII(1, 1)) {
            VIS[p.X][p.Y] = 1;
            ret += DST[1][1][p.X][p.Y];
            p = PR[1][1][p.X][p.Y];
        }
      */  
        FOR (i, 1, N) FOR (j, 1, M) if (A[i][j] != '.' && !VIS[i][j]) 
            ret += DDD[i][j];
        
    return ret;
}

int main(int argc, char ** argv) { ios::sync_with_stdio(false);
    COND = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
    int T; cin >> T;
    FOR (my, 1, T) {
        DB(my);
        printf("Case #%d: %d\n", my, solve());
    }

    return 0;
}

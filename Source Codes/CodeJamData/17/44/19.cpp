
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)

#define pb push_back
#define mp make_pair
#define st first
#define nd second


using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector <pii> VP;
typedef vector <ll> VL;
typedef vector <pll> VPL;

typedef vector <VI> VVI;
typedef vector <VL> VVL;
typedef vector <VB> VVB;
typedef vector <VP> VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000000000000001LL;

/*************************************************************************/

const int MAXN = 20;

bool dp[1 << MAXN];
pii best[1 << MAXN];

const int MAXSOLD = 10;
const int MAXTURR = 10;

bool canKill[MAXSOLD][MAXTURR][1 << MAXTURR];

/*************************************************************************/

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

VP solve(int n, int m, int k, vector <string> &tab) {
    int nSold = 0, nTurr = 0;
    VP solds, turrs;
    
    FOR(i,0,n-1) FOR(j,0,m-1) {
        if (tab[i][j] == 'S') {
            nSold++;
            solds.pb({i, j});
        } else if (tab[i][j] == 'T') {
            nTurr++;
            turrs.pb({i, j});
        }
    }
    
    int t = nSold + nTurr;
    int T = 1 << t;
    
    FOR(mask,0,T-1) {
        dp[mask] = false;
    }
    
    dp[T-1] = true;
    
    bool canLeave[n][m], canShootFrom[n][m];
    int dist[n][m];
    
    int TURR = 1 << nTurr;
    FOR(sold,0,nSold-1) FOR(turr,0,nTurr-1) FOR(mask,0,TURR-1) if (mask & (1 << turr)) {
        canKill[sold][turr][mask] = false;
    
        FOR(i,0,n-1) FOR(j,0,m-1) canLeave[i][j] = true;
        FOR(i,0,n-1) FOR(j,0,m-1) canShootFrom[i][j] = false;
        FOR(i,0,n-1) FOR(j,0,m-1) dist[i][j] = -1;
        
        FOR(otherTurr,0,nTurr-1) if (mask & (1 << otherTurr)) {
            FOR(dir,0,3) {
                int x = turrs[otherTurr].st, y = turrs[otherTurr].nd;
                
                while (valid(x, y, n, m) && tab[x][y] != '#') {
                    canLeave[x][y] = false;
                    
                    x += dx[dir];
                    y += dy[dir];
                }
            }
        }
        
        FOR(dir,0,3) {
            int x = turrs[turr].st, y = turrs[turr].nd;
            
            while (valid(x, y, n, m) && tab[x][y] != '#') {
                canShootFrom[x][y] = true;
                
                x += dx[dir];
                y += dy[dir];
            }
        }
        
        queue <pii> q;
        
        pii src = solds[sold];
        
        dist[src.st][src.nd] = 0;
        q.push(src);
        
        while (!q.empty()) {
            auto e = q.front(); q.pop();

            if (canShootFrom[e.st][e.nd]) {
                canKill[sold][turr][mask] = true;
                break;
            }

            if (!canLeave[e.st][e.nd]) continue;            
            if (dist[e.st][e.nd] >= k) continue;
            
            FOR(dir,0,3) {
                int nx = e.st + dx[dir];
                int ny = e.nd + dy[dir];
                
                if (valid(nx, ny, n, m) && tab[nx][ny] != '#' && dist[nx][ny] == -1) {
                    dist[nx][ny] = 1 + dist[e.st][e.nd];
                    q.push({nx, ny});
                }
            }
        }
    }
    
    FORD(mask,T-1,1) if (dp[mask]) {
        int turrMask = 0;
        FOR(turr,0,nTurr-1) if (mask & (1 << (nSold + turr))) {
            turrMask |= (1 << turr);
        }
    
        FOR(sold,0,nSold-1) if (mask & (1 << sold)) {
            FOR(turr,0,nTurr) if (turrMask & (1 << turr)) {
                if (canKill[sold][turr][turrMask]) {
                    int newMask = mask;
                    newMask ^= (1 << sold);
                    newMask ^= (1 << (nSold + turr));
                    
                    dp[newMask] = true;
                    best[newMask] = {sold, turr};
                }
            }
        }
    }
    
    int bestAns = 0;
    FOR(mask,0,T-1) if (dp[mask]) {
        bestAns = max(bestAns, (t - __builtin_popcount(mask)) / 2);
    }
    
    int mask = 0;
    FOR(mask,0,T-1) if (dp[mask] && (t - __builtin_popcount(mask)) / 2 == bestAns) {
        VP ans;
        
        int v = mask;
        
        while (v != T-1) {
            auto b = best[v];
            ans.pb(b);
            
            v |= (1 << b.st);
            v |= (1 << (nSold + b.nd));
        }

        reverse(ans.begin(), ans.end());        
        return ans;
    }

    assert(false);    
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    
    FOR(i,1,t) {
        cout << "Case #" << i << ": ";
        
        int n, m, k;
        cin >> m >> n >> k;
        
        vector <string> tab(n);
        FOR(j,0,n-1) {
            cin >> tab[j];
        }
        
        VP ans = solve(n, m, k, tab);
        
        cout << SIZE(ans) << '\n';
        for (auto &e : ans) {
            cout << e.st + 1 << ' ' << e.nd + 1 << '\n';
        }
    }

    return 0;
}

/*************************************************************************/


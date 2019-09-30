#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>

#define FOR(x,a,b) for(int x=(a); x<(b); x++)
#define FI(b) FOR(i,0,b)
#define FJ(b) FOR(j,0,b)
#define FK(b) FOR(k,0,b)
#define FC(b) FOR(c,0,b)
#define EACH(v,it) for(__typeof(v.begin()) it=v.begin(); it!=v.end(); it++)

using namespace std;

vector<string> m;
int rown, coln;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int setbit(int state, int r, int c) {
    int p = r * coln + c;
    return state | (1<<p);
}

int getbit(int state, int r, int c) {
    int p = r * coln + c;
    return (state & (1<<p)) !=0;
}

int cache[1<<16][4][4];

bool win(int state, int kr, int kc) {
    int &ans = cache[state][kr][kc];
    if (ans >= 0) return ans;

    ans = 0;
    FOR(d,0,8) {
        int nr = kr + dx[d];
        int nc = kc + dy[d];
        if (nr<0 || nc<0 || nr>=rown || nc>=coln || m[nr][nc] == '#') continue;
        if (getbit(state, nr, nc)) continue;

        if (!win(setbit(state, nr, nc), nr, nc)) {
            ans = true;
            break;
        }
    }
    return ans;

}

int main() {
	int cases;
	cin >> cases;
	FC(cases) {
        cin >> rown >> coln;

        m.resize(rown);
        FI(rown) cin >> m[i];

        int kr=-1, kc;
        FI(rown) FJ(coln) if (m[i][j] == 'K') { kr = i; kc = j; }

        memset(cache,-1,sizeof(cache));
        cout << "Case #" << (c+1)<<": " << (win(setbit(0,kr,kc),kr,kc) ? "A" : "B") << endl;
	}
}

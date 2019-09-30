#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define mp(y,x) make_pair(y,x)

using namespace std;

typedef pair<int,int> cell;
#define y first
#define x second
typedef vector<cell> piece;

int dy[] = {-1,0,1,0};
int dx[] = {0,-1,0,1};

piece shift(piece a) {
    sort(a.begin(),a.end());
    int mx = 1e9, my = 1e9;
    for (cell v : a) {
        mx = min(mx, v.x);
        my = min(my, v.y);
    }
    for (cell &v : a) {
        v.x -= mx;
        v.y -= my;
    }
    return a;
}

piece flipx(piece a) {
    for (cell &v : a) v.x *= -1;
    return a;
}

piece flipy(piece a) {
    for (cell &v : a) v.y *= -1;
    return a;
}

piece rot(piece a) {
    for (cell &v : a) {
        int tx = v.x, ty = v.y;
        v.x = -ty; v.y = tx;
    }
    return a;
}

piece normalise(piece a) {
    piece res = shift(a);
    FO(i,0,2) FO(j,0,2) FO(k,0,4) {
        piece b = a;
        if (i) b = flipx(b);
        if (j) b = flipy(b);
        FO(Z,0,k) b = rot(b);
        b = shift(b);
        res = min(res, b);
    }
    return res;
}

set<piece> seen;
vector<piece> all[25];

void genpiece(int x, piece v) {
    v = normalise(v);
    if (seen.count(v)) return;
    seen.insert(v);
    if (x == sz(v)) {
        all[x].push_back(v);
        return;
    }

    for (auto p : v) {
        FO(i,0,4) {
            int ny = p.y+dy[i];
            int nx = p.x+dx[i];
            if (!binary_search(v.begin(),v.end(),mp(ny,nx))) {
                piece nv = v;
                nv.emplace_back(ny,nx);
                genpiece(x, nv);
            }
        }
    }
}

bool grid[25][25];
int dfcnt;

void dfs(int h, int w, int y, int x) {
    if (grid[y][x]) return;
    dfcnt++;
    grid[y][x] = true;
    FO(i,0,4) {
        int ny = y+dy[i], nx=x+dx[i];
        if (0 <= ny && ny < h && 0 <= nx && nx < w) dfs(h,w,ny,nx);
    }
}

bool canwin(int h, int w, int py, int px, piece p) {
    FO(y,0,h) FO(x,0,w) grid[y][x] = false;
    for (cell c : p) {
        int y = py + c.y, x = px + c.x;
        if (0 <= y && y < h && 0 <= x && x < w) grid[y][x] = true;
        else return false;
    }
    FO(y,0,h) FO(x,0,w) if (!grid[y][x]) {
        dfcnt = 0;
        dfs(h,w,y,x);
        if (dfcnt % sz(p) != 0) return false;
    }
    return true;
}

bool canwin_place(int h, int w, piece p) {
    FO(y,0,h) FO(x,0,w) if (canwin(h,w,y,x,p)) return true;
    return false;
}

bool canwin_piece(int h, int w, piece p) {
    seen.clear();
    FO(i,0,2) FO(j,0,2) FO(k,0,4) {
        piece b = p;
        if (i) b = flipx(b);
        if (j) b = flipy(b);
        FO(Z,0,k) b = rot(b);
        b = shift(b);
        if (!seen.count(b)) {
            seen.insert(b);
            if (canwin_place(h,w,b)) return true;
        }
    }
    seen.clear();
    return false;
}

bool candefeat(int h, int w, int x) {
    if (x >= 7) return true;
    if ((h*w) % x != 0) return true;
    for (piece p : all[x]) if (!canwin_piece(h,w,p)) return true;
    return false;
}

bool cache[25][25][25];

int main() {
    FO(x,1,7) {
        //printf("x=%d\n", x);
        seen.clear();
        genpiece(x,{{0,0}});
        seen.clear();
        //printf("#=%d\n", sz(all[x]));
    }
    FO(h,1,22) FO(w,1,22) FO(x,1,22) {
        cache[h][w][x] = candefeat(h,w,x);
    }

    int T; scanf("%d", &T);
    FO(Z,1,T+1) {
        int x, h, w; scanf("%d %d %d", &x, &h, &w);
        char ans[50]; sprintf(ans, "Case #%d: ", Z);
        if (!cache[h][w][x]) strcat(ans, "GABRIEL");
        else strcat(ans, "RICHARD");
        printf("%s\n", ans);
    }
}


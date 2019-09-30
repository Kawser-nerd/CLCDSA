#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

const int inf = 0x7fffffff;

struct Block {
    int n, p[5], sX, sY;

    int Tidy() {
        int x0 = inf, y0 = inf;
        sX = sY = -inf;
        for (int i = 0; i < n; ++i) {
            char* c = (char*)&p[i];
            if (c[0] < x0) x0 = c[0];
            if (c[1] < y0) y0 = c[1];
            if (c[0] > sX) sX = c[0];
            if (c[1] > sY) sY = c[1];
        }
        for (int i = 0; i < n; ++i) {
            char* c = (char*)&p[i];
            c[0] -= x0;
            c[1] -= y0;
        } 
        sX -= x0 - 1;
        sY -= y0 - 1;
        sort(p, p + n);
        n = unique(p, p + n) - p;
        int ret = 0;
        *((char*)&ret + 0) = x0;
        *((char*)&ret + 1) = y0;
        return ret;
    }

    bool Exists(int x, int y) const {
        int v = 0;
        *((char*)&v + 0) = x;
        *((char*)&v + 1) = y;
        return find(p, p + n, v) != p + n;
    }

    int Compare(Block const& s) const {
        if (n != s.n) return n - s.n;
        for (int i = 0; i < n; ++i)
            if (p[i] != s.p[i])
                return p[i] - s.p[i];
        return 0;
    }

    bool operator<(Block const& s) const {
        return Compare(s) < 0;
    }
    bool operator==(Block const& s) const {
        return Compare(s) == 0;
    }
};

map<Block, int> b2i;
vector<Block> i2b;

void Generate() {
    queue<Block> q;
    Block b0;
    b0.n = 1;
    b0.p[0] = 0;
    b0.Tidy();
    q.push(b0);
    b2i[b0] = -1;
    while (!q.empty()) {
        b0 = q.front();
        q.pop();
        if (b0.n == 5) continue;
        for (int i = 0; i < b0.n; ++i)
            for (int j = 0; j < 4; ++j) {
                Block b1(b0);
                char* w = (char*)&(b1.p[b1.n]);
                char* p0 = (char*)&(b0.p[i]);
                w[0] = j % 2 * 2 - 1;
                w[1] = w[2] = w[3] = 0;
                if (j / 2) swap(w[0], w[1]);
                w[0] += p0[0];
                w[1] += p0[1];
                ++b1.n;
                b1.Tidy();
                if (!b2i.count(b1)) {
                    b2i[b1] = 0;
                    q.push(b1);
                }
            }
    }
    int k = 0;
    i2b.resize(b2i.size());
    for (map<Block, int>::iterator it = b2i.begin(); it != b2i.end(); ++it) {
        i2b[k] = it->first;
        it->second = k++;
    }
    cerr << "# of pattern = " << b2i.size() << endl;
}

int R, C;
char bd[20][20];

int GetId(Block const& b) {
    Block b1(b);
    int p0 = b1.Tidy();
    map<Block, int>::iterator it = b2i.find(b1);
    if (it == b2i.end()) return -1;
    return (it->second * R + (p0 & 255)) * C + (p0 >> 8 & 255);
}

Block GetBlock(int id) {
    int x0 = id / C % R, y0 = id % C, bid = id / (R * C);
    Block b = i2b[bid];
    for (int i = 0; i < b.n; ++i) {
        char* p = (char*)&b.p[i];
        p[0] += x0;
        p[1] += y0;
    }
    return b;
}

bool Okay(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C) return false;
    if (bd[x][y] == -1) return false;
    return true;
}

bool Move(Block& b, int id, int dir) {
    int dx = dir % 2 * 2 - 1, dy = 0;
    if (dir / 2) swap(dx, dy);
    int x1 = (b.p[id] & 255) + dx, y1 = (b.p[id] >> 8 & 255) + dy;
    int x0 = (b.p[id] & 255) - dx, y0 = (b.p[id] >> 8 & 255) - dy;
    if (!Okay(x0, y0) || !Okay(x1, y1)) return false;
    if (b.Exists(x0, y0) || b.Exists(x1, y1)) return false;
    b.p[id] = y0 << 8 | x0;
    return true;
}

void FillBd(Block const& b, int val) {
    for (int i = 0; i < b.n; ++i)
        bd[b.p[i] & 255][b.p[i] >> 8 & 255] ^= 1 << val;
}

int dist[100 * 12 * 12];

int BFS(int src, int dst) {
    if (src == -1 || dst == -1) return -1;
    fill(dist, dist + b2i.size() * R * C, -1);
    dist[src] = 0;
    queue<pair<Block, int> > q;
    q.push(make_pair(GetBlock(src), 0));
    while (!q.empty() && dist[dst] == -1) {
        Block b0 = q.front().first;
        int c0 = q.front().second;
        q.pop();

        for (int i1 = 0; i1 < b0.n; ++i1) for (int d1 = 0; d1 < 4; ++d1) {
            Block b1(b0);
            if (!Move(b1, i1, d1)) continue;
            int id1 = GetId(b1);
            if (c0 % 2 && id1 == -1) continue;
            if (id1 != -1 && dist[id1] != -1) continue;
            if (id1 != -1) dist[id1] = c0 / 2 + 1;
            q.push(make_pair(b1, (c0 / 2 + 1) * 2 + (id1 == -1)));
        }
    }
    return dist[dst];
}

int solve() {
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        cin >> bd[i];
    int sid, tid;
    {
        Block b;
        b.n = 0;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (bd[i][j] == 'o' || bd[i][j] == 'w') {
                    char* p = (char*)&b.p[b.n++];
                    p[0] = i;
                    p[1] = j;
                    p[2] = p[3] = 0;
                }
        sid = GetId(b);
    }
    {
        Block b;
        b.n = 0;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (bd[i][j] == 'x' || bd[i][j] == 'w') {
                    char* p = (char*)&b.p[b.n++];
                    p[0] = i;
                    p[1] = j;
                    p[2] = p[3] = 0;
                }
        tid = GetId(b);
    }
    {
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j) {
                char& p = bd[i][j];
                if (p == '#')
                    p = -1;
                else
                    p = 0;
            }
    }
    return BFS(sid, tid);
}

int main(int argc, char* argv[]) {
    Generate();
    if (argc > 1) {
        freopen((string(argv[1]) + ".in").c_str(), "r", stdin);
        freopen((string(argv[1]) + ".out").c_str(), "w", stdout);
    }
    int cc = 0, ccc = 0;
    for (cin >> ccc; cc < ccc; ++cc)
            cout << "Case #" << cc + 1 << ": " << solve() << endl;
    return 0;
}

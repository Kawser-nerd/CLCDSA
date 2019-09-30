#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <memory>

using namespace std;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define INF 1000000000
#define X first
#define Y second
#define pb push_back

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

struct Node {
    Node (int x, int y, int v) {
        this->x = x;
        this->y = y;
        this->maxv = v;
        this->minv = v;
    }

    int getMin(int x, int y) {
        if (y <= this->x || x >= this->y)
            return INF;
        if (x <= this->x && y >= this->y)
            return this->minv;
        if (!left)
            return this->minv;

        return min(left->getMin(x, y), right->getMin(x,y));
    }

    void update(int x, int y, int v) {
        //cout << x << " " << y << " " << this->x << " " << this->y << " " << v << endl;
        if (y <= this->x || x >=this->y)
            return;
        if (v <= this->minv)
            return;
        if (x <= this->x && y>= this->y && v >= this->maxv) {
            left.reset (nullptr);
            right.reset (nullptr);
            this->maxv = v;
            this->minv = v;
        } else {
            if (!left) {
                int mid = (this->x + this->y) / 2;
                left.reset (new Node(this->x, mid, this->minv));
                right.reset (new Node(mid, this->y, this->minv));
            }
            left->update(x, y, v);
            right->update(x,y, v);

            this->minv = min(left->minv, right->minv);
            this->maxv = max(left->maxv, right->maxv);
        }
    }

    int x, y;
    int minv, maxv;
    std::unique_ptr<Node> left, right;
};

struct Attack{
    Attack (int x, int y, int s) : x(x), y(y), s(s) {}
    int x, y, s;
};

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w+", stdout);

    int t;
    cin >> t;
    REP (tt, t) {
        std::cout << "Case #" << tt+1 << ": ";

        std::unique_ptr<Node> node(new Node(-INF, INF, 0));

        std::vector<std::vector<Attack> > a(676061);

        int N;
        cin >> N;
        while (N--) {
            int d, n, x, y, s, dd, dp, ds;
            cin >> d >> n >> x >> y >> s >> dd >> dp >> ds;

            while (n--) {
                a[d].pb(Attack(x, y, s));
                d += dd;
                x += dp;
                y += dp;
                s += ds;
            }
        }

        int res =0;

        REP (i, a.size())
        {
            for (auto& attack: a[i])
                if (node->getMin(attack.x, attack.y) < attack.s)
                    res ++;

            for (auto& attack: a[i])
                node->update(attack.x, attack.y, attack.s);
        }

        cout << res << endl;
    }

    return 0;
}

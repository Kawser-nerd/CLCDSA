#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

#define fabsl __builtin_fabsl
#define atan2l __builtin_atan2l
#define cosl __builtin_cosl
#define sinl __builtin_sinl
#define sqrtl __builtin_sqrtl
#define acosl __builtin_acosl

#define POINTT int // Dla wspolrzednych punktu (int lub double)
#define POINTR LL // Dla wynikow operacji - pole, iloczyn wektorowy (LL lub double)
struct POINT {
    POINTT x,y;
    POINT(POINTT wx, POINTT wy) : x(wx), y(wy) {}
    POINT() {}
    bool operator ==(POINT& a) {return a.x==x && a.y==y;}
};
#define Det(p1,p2,w) (POINTR(p2.x-p1.x)*POINTR(w.y-p1.y)-POINTR(p2.y-p1.y)*POINTR(w.x-p1.x))
bool CCmpH(POINT *a, POINT *b) {
    return a->x==b->x ? a->y<b->y : a->x<b->x;
}
#define XCAL {while((int)w.size()>m && Det((*w[w.size()-2]), (*w[w.size()-1]), (*s[x]))<=0) w.pop_back(); w.PB(s[x]);}
vector<POINT*> ConvexHull(vector<POINT>& p) {
    vector<POINT*> s,w;
    FORE(it,p) s.PB(&*it);
    sort(ALL(s),CCmpH);
    int m=1;
    REP(x,(int)s.size()) XCAL
    m=w.size();
    FORD(x,(int)s.size()-2,0) XCAL
    if ((int) w.size() > 1) {
        w.pop_back();
    }
    return w;
}

/*
 //Begin of the code
int main() {
    vector<POINT> a;
    a.PB(POINT(0,0));
    a.PB(POINT(1,0));
    a.PB(POINT(1,1));
    a.PB(POINT(0,1));
    vector<POINT*> res = ConvexHull(a);
    FOREACH(it, res) cout << (*it)->x << " " << (*it)->y << endl;
    return 0;
}*/

typedef POINT Point;

struct Helper {
    vector<Point> points;

    void addPoint(const Point& p) {
        points.PB(p);
    }

    void goHull() {
        vector<Point> v = points;
        points.clear();
        vector<Point*> hull = ConvexHull(v);
        FORE (it, hull) {
            points.PB(**it);
        }
    }
};

struct Event {
    int index;
    LD ang;
    Point *choice;
};

bool operator < (const Event& a, const Event& b) {
    return a.ang < b.ang;
}

void alg() {
    int n, m;
    cin >> n >> m;
    Helper helpers[4];
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        int v = x + y;
        int w = x - y;
        for (int j = 0; j < 4; ++j) {
            helpers[j].addPoint(Point(w, v));
            w = -w;
            swap(v, w);
        }
    }
    for (int i = 0; i < 4; ++i) {
        helpers[i].goHull();
    }
    vector<Event> events;
    for (int i = 0; i < 4; ++i) {
        int sz = (int) helpers[i].points.size();
        for (int j = 0; j < sz; ++j) {
            int pr = (j + sz - 1) % sz;
            Event e;
            if (pr == j) {
                e.ang = 0;
            } else {
                e.ang = atan2l(helpers[i].points[j].y - helpers[i].points[pr].y,
                               helpers[i].points[j].x - helpers[i].points[pr].x);
            }
            e.choice = &helpers[i].points[j];
            e.index = i;
            static const LD pi = 2 * acosl(0);
            for (int i = -2; i <= 2; ++i) {
                Event c = e;
                c.ang += i * 2 * pi;
                events.PB(c);
            }
        }
    }
    sort(ALL(events));
    Point *best[4];
    for (int i = 0; i < 4; ++i) {
        best[i] = NULL;
    }
    LD result = 0;
    FORE (it, events) {
        best[it->index] = it->choice;
        for (int k = max(1, m - 3); k <= m; ++k) {
            LL sx = 0;
            LL sy = 0;
            bool bad = false;
            for (int i = 0; i < 4; ++i) {
                int used = k / 4 + bool(k % 4 > i);
                if (used > 0 && best[i] == NULL) {
                    bad = true;
                    break;
                }
                if (used > 0) {
                    sx += used * (LL) best[i]->x;
                    sy += used * (LL) best[i]->y;
                }
            }
            if (bad) {
                continue;
            }
            result = max(result, sqrtl(sx * (LD) sx + sy * (LD) sy));
        }
    }
    printf("%.9Lf\n", result);
    fflush(stdout);
}

int main() {
    int d;
    cin >> d;
    for (int case_no = 1; case_no <= d; ++case_no) {
        cout << "Case #" << case_no << ": ";
        alg();
    }
}

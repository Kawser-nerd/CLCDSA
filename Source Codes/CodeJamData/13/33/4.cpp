#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forit(i, v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;

struct rec{
    int l, r, s, d;
    rec(){}
};

bool operator < (const rec& a, const rec& b){
    return a.d < b.d;
}

int getid(int v, vector<int>& a){
    return lower_bound(all(a), v) - a.begin();
}

void push(vector<pt>& t, int idx){
    if(t[idx].X != -1){
        int cur = t[idx].X;
        t[idx].X = -1;

        fore(dx, 1, 3){
            t[2*idx+dx].X = max(t[2*idx+dx].X, cur);
            t[2*idx+dx].Y = max(t[2*idx+dx].Y, t[2*idx+dx].X);
        }
    }
}

void upd(vector<pt>& t, int lf, int rg, int val, int idx, int tlf, int trg){
    if(lf == tlf && rg == trg){
        t[idx].X = max(t[idx].X, val);
        t[idx].Y = max(t[idx].Y, t[idx].X);
        return;
    }

    push(t, idx);
    int mid = (tlf + trg) >> 1;

    if(lf <= mid)
        upd(t, lf, min(mid, rg), val, 2*idx+1, tlf, mid);
    if(rg >= mid+1)
        upd(t, max(lf, mid+1), rg, val, 2*idx+2, mid+1, trg);
    t[idx].Y = min(t[2*idx+1].Y, t[2*idx+2].Y);
}

int getmin(vector<pt>& t, int lf, int rg, int idx, int tlf, int trg){
    if(lf == tlf && rg == trg)    
        return t[idx].Y;

    push(t, idx);
    int mid = (tlf + trg) >> 1;

    int ans = INF;
    if(lf <= mid)
        ans = min(ans, getmin(t, lf, min(mid, rg), 2*idx+1, tlf, mid));
    if(rg >= mid+1)
        ans = min(ans, getmin(t, max(lf, mid+1), rg, 2*idx+2, mid+1, trg));
    t[idx].Y = min(t[2*idx+1].Y, t[2*idx+2].Y);
    return ans;
}

int main() {
    #ifdef myproject
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    #endif

    int tests;
    cin >> tests;
    forn(testsit, tests){
        printf("Case #%d: ", testsit+1);

        int n;
        cin >> n;

        vector<rec> q;
        forn(i, n){
            int di, ni, wi, ei, si, ddi, dpi, dsi;
            cin >> di >> ni >> wi >> ei >> si >> ddi >> dpi >> dsi;

//            cerr << di << " " << ni << " " << wi << " " << ei << " " << si << " " << ddi << " " << dpi << " " << dsi << endl;

            forn(step, ni){
                rec cur;
                cur.l = wi, cur.r = ei, cur.s = si, cur.d = di;
                q.pb(cur);
                di += ddi, wi += dpi, ei += dpi, si += dsi;
            }
        }

        sort(all(q));

        vector<int> ws;
        forn(i, sz(q)){
            ws.pb(q[i].l);
            ws.pb(q[i].r - 1);
            ws.pb(q[i].r);
            ws.pb(q[i].l - 1);
        }
        sort(all(ws));
        ws.erase(unique(all(ws)), ws.end());

        vector<pt> c(5*sz(ws));
        forn(i, sz(c))
            c[i].X = -1, c[i].Y = 0;

        int ans = 0;

        forn(i, sz(q)){
            int j = i;
            while(j < sz(q) && q[i].d == q[j].d){

                //cerr << q[j].d << " " << q[j].l << " " << q[j].r << " " << q[j].s << endl;

                int lf = getid(q[j].l, ws), rg = getid(q[j].r - 1, ws);

//                cerr << lf << " " << rg << " " << sz(ws) << endl;

                int minv = getmin(c, lf, rg, 0, 0, sz(ws) - 1);

//                cerr << minv << endl;

                if(minv < q[j].s)
                    ans++;    

                j++;
            }

            fore(r, i, j){
                int lf = getid(q[r].l, ws), rg = getid(q[r].r - 1, ws);
                upd(c, lf, rg, q[r].s, 0, 0, sz(ws) - 1);
            }

            i = j - 1;
        }

        cout << ans;

        puts("");
        cerr << "testsit=" << testsit+1 << " " << clock() << endl;
    }
    return 0;
}



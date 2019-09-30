#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))

void solve();
void test();
int main() {
  int test_case; cin >> test_case;
  REP(t, test_case) {
    printf("Case #%d: ", t+1);
    // test();
    solve();
  }
}
//-------------------------------

struct D { ll min_value; bool delay; };
struct SegTree {
  static const int n = 1<<23;  // the number of leaves
  // static const int n = 1<<3;  // the number of leaves
  D v[2*n];
 
  void init(ll x) { REP(i, 2*n) v[i] = (D){x, false}; }
 
  void remove_delay(int node) {
    if (v[node].delay) {
      if (node < n) {
        if (v[node*2+0].min_value < v[node].min_value) v[node*2+0] = v[node];
        if (v[node*2+1].min_value < v[node].min_value) v[node*2+1] = v[node];
      }
      v[node].delay = false;
    }
  }
 
  ll join(int node) {
    ll vl = v[node*2+0].min_value;
    ll vr = v[node*2+1].min_value;
    return min(vl, vr);
  }
 
  void osub(int node, int lp, int rp, int fr, int to, ll value) {
    if (rp<=fr || to<=lp) return;
    if (fr<=lp && rp<=to) {
      if (v[node].min_value < value) v[node] = (D){value, true};
      return;
    }
    remove_delay(node);
    int mp = (lp+rp)/2;
    osub(node*2+0, lp, mp, fr, to, value);
    osub(node*2+1, mp, rp, fr, to, value);
 
    if (node < n) {
      v[node].min_value = join(node);
    }
  }
  void overwrite(int fr, int to, ll value) { osub(1, 0, n, fr, to, value); }
 
  ll msub(int node, int lp, int rp, int fr, int to) {
    if (rp<=fr || to<=lp) return 1LL<<60;
    if (fr<=lp && rp<=to) {
      return v[node].min_value;
    }
    remove_delay(node);
    int mp = (lp+rp)/2;
    ll vl = msub(node*2+0, lp, mp, fr, to);
    ll vr = msub(node*2+1, mp, rp, fr, to);
    return min(vl, vr);
  }
  ll get_min(int fr, int to) { return msub(1, 0, n, fr, to); }
 
  // DEBUG
  void outp(int node) {
    printf("(%I64d %d) ", v[node].min_value, v[node].delay);
  }
  void outpu() {
    int u=2;
    FOR(i, 1, 2*n) {
      printf("%d:", i);
      outp(i);
      if (i==u-1) { puts(""); u*=2; }
    }
  }
};

struct Q {
  ll lo, hi, val;
  Q(ll lo, ll hi, ll val) : lo(lo), hi(hi), val(val){}
};
map<ll, vector<Q> > query;
SegTree seg;


void test() {
  seg.init(0LL);

  seg.overwrite(0, 2, 2);
  seg.overwrite(3, 4, 2);
  seg.overwrite(0, 4, 1);

  seg.outpu();

  cout << seg.get_min(0, 1) << endl;
  cout << seg.get_min(1, 2) << endl;;
  cout << seg.get_min(2, 3) << endl;;
  cout << seg.get_min(3, 4) << endl;;
}

void solve() {
  query.clear();
  {
    ll nnn; cin >> nnn;
    REP(i, nnn) {
      ll t0, turn, w0, e0, s0, diff_t, diff_d, diff_s;
      cin >>  t0 >>  turn>> w0>> e0>> s0>> diff_t>> diff_d>> diff_s;

      REP(i, turn) {
        query[t0].push_back(Q(w0, e0, s0));

        w0 += diff_d;
        e0 += diff_d;
        t0 += diff_t;
        s0 += diff_s;
      }
    }
  }

  // we must compress...
  map<ll, ll> comp;
  FORIT(it, query) FORIT(itt, it->second) {
    // cout<<it->first<<" : " << itt->lo<<" "<<itt->hi<<" "<<itt->val<<endl;
    comp[itt->lo]=-1;
    comp[itt->hi]=-1;
  }
  int uuu = 0;
  FORIT(it, comp) it->second = uuu++;
  FORIT(it, query) FORIT(itt, it->second) {
    itt->lo=comp[itt->lo];
    itt->hi=comp[itt->hi];
  }

  assert(uuu < 1<<23);

  seg.init(0LL);

  ll res = 0;
  FORIT(it, query) {
    // count the successful attacks
    // cout<<"DAY"<<it->first<<endl;
    FORIT(itt, it->second) {
      ll v = seg.get_min(itt->lo, itt->hi);
      if (v < itt->val) {
        res++;
        // cout<<"#"<<endl;
      }
    }
    // update the height of the Wall
    FORIT(itt, it->second) {
      seg.overwrite(itt->lo, itt->hi, itt->val);
    }
  }

  cout << res << endl;
}

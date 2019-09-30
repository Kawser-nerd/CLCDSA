
#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef complex<LL> PII;
typedef complex<LL> P;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

LL one;
LL zero;
const int MX = 5e5+2;
const int dig = 1e6;

LL val(P p) {
    return dig*p.imag() - one*p.real();
}
bool comp(P a, P b) {
    return val(a) < val(b);
}

LL vec(P a, P b) {
    return real(a)*imag(b)-real(b)*imag(a);
} 


bool remove(P a, P b, P c) {
   // debug(MP(MP(a,b),c));
  //  debug(vec(b-a,c-a));
    return vec(b-a, c-a) >= 0;     
}

P best;
int who;
P want;

void test(P p, P q) {
    P diff = q-p;
    //debug(diff.imag()*1000/diff.real());
  //  debug(best.imag()*1000/best.real());
   // debug(want.imag()*1000/want.real());
    LL cur = imag(diff)*real(best)*real(want);
    LL w = imag(want)*real(diff)*real(best);
    LL b = imag(best)*real(diff)*real(want);
    if (abs(cur-w) < abs(b-w) || (abs(cur-w) == abs(b-w) && p.real() < who)) {
        who = (int)p.real();
        best = diff;
    }
}
namespace std {
    bool operator < (P a, P b) {
        return a.real() < b.real();
    }
};

struct ot {
    set<PII> S;
    ot() {} 
    void add(P p) {
        while(true) {
            auto n1 = S.lower_bound(p);
            auto n2 = n1;
            if (n1 == S.end()) break;
            ++n2;
            test(p,*n1);
            if (n2 == S.end()) break;
            if (remove(p, *n1, *n2)) S.erase(n1);
            else break;
        }
        while(true) {
            auto p1 = S.lower_bound(p);
            if (p1 == S.begin()) break;
            --p1;
            test(*p1, p);
            auto p2 = p1;
            if (p2 == S.begin()) break;
            --p2;
            if (remove(*p2, *p1, p)) S.erase(p1);
            else break;
        }
        S.insert(p);
        //debugv(S);
    }
};

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int n;
    cin >> n;
    LD D;
    cin >> D;
    one = round(D*1e6);
    vector<PII> V;
    int ax = 0, ay = 0;
    string S;
    cin >> S;
    V.PB(P(ax,ay));
    REP(i,n) {
        if (S[i] == '1') ++ay;
        ++ax;
        V.PB(P(ax,ay));
    }
    sort(ALL(V), comp);
    ot o;
    want = P( 1e6, one);
    best = P(1,3);
    who = -1;
    FORE(it, V) {
        o.add(*it);
    }
    cout << who << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);
    return 0;
}


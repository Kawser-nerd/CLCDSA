
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

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

typedef pair<LL,LL> score;

vector<LL> eval(score a) {
    vector<LL> res;
    res.PB(abs(a.X - a.Y));
    res.PB(a.X);
    res.PB(a.Y);
    return res;
}
const LL INF = 1e18;

char match(char a, char b) {
    if (a == '?' && b == '?') return '0';
    if (a == '?') return b;
    if (b == '?') return a;
    if (a == b) return a;
    return '-';
}

char mx(char a) {
    if (a == '?') return '9';
    else return a;
}
char mn(char a) {
    if (a == '?') return '0';
    else return a;
}

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    string a,b;
    cin >> a >> b;
    int n = SZ(a);
    score s = MP(INF,0ll);
    REP(i, n) REP(va, 10) REP(vb, 10) {
        if (va == vb && i != n-1) continue;
        int ok = -1;
        LL A = 0, B = 0;
        REP(j, n) {
            if (j < i) {
                char m = match(a[j], b[j]);
                if (m == '-') {
                    ok = j;
                    break;
                }
                A = 10*A + m - '0';
                B = 10*B + m - '0';
            } else if (j == i) {
                if (match(a[j],va + '0') == '-' || match(b[j], vb + '0') == '-') {
                    ok = j;
                    break;
                } 
                A = 10*A + va;
                B = 10*B + vb;
            } else {
                if (va < vb) {
                    A = 10*A + mx(a[j]) - '0';
                    B = 10*B + mn(b[j]) - '0';
                } else {
                    A = 10*A + mn(a[j]) - '0';
                    B = 10*B + mx(b[j]) - '0';
                }
            }
        }
        if (ok != -1) continue;
        score cur(A,B);
        if (eval(cur) < eval(s)) s = cur;
    }
    cout <<  std::setfill('0') << std::setw(n) << s.X << " " <<  std::setfill('0') << std::setw(n) << s.Y << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}


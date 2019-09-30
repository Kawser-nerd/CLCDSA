#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<stack>
#include<bitset>
#include<unordered_map>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef complex<LD>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<typename T1, typename T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { out << "(" << pair.FI << ", " << pair.SE << ")"; return out; }

inline LD operator^(const P& a,const P& b){return real(a)*imag(b)-imag(a)*real(b);}//iloczyn wektorowy
inline LD operator%(const P& a,const P& b){return real(a)*real(b)+imag(a)*imag(b);}//iloczyn skalarny
inline LD wek(const P& a,const P& b,const P& c){return (b-a)^(c-a);}

int T,n;
//P obrot = polar(1.0l, 0.94712167213243245391l);
vector<P> p;

LD sample(P s) {
    vector<LD> res;
    FORE(i,p) res.PB(s%(*i));
    sort(ALL(res));
//    cout << s << "    " << (res[2*n]-res[2*n-1])*1E6 << " " << res[2*n] << "!" << endl;
    return 0.5l * (res[2*n-1] + res[2*n]);
}

P resA, resB;
LD last;

int val(LD kat) {
//    debug(kat);
    P v1 = polar(1.0l, kat);
    P v2 = v1 * P(0,1.0l);
    LD s1 = sample(v1);
    LD s2 = sample(v2);
/*    debug(v1);
    debug(v2);
    debug(s1);
    debug(s2); */
    resA = s1 * v1 + s2 * v2;
    resB = resA + 10000000.0l*v1;
    last = kat;
    int res = 0;
    FORE(i,p) if((*i%v1) > s1) {
        res += ((*i%v2) > s2 ? 1 : -1);
    }
    if(res == 0) {
//        cout << v1 << " " << s1 << "   " << v2 << "   " << s2 << endl;
        int cnt[4];
        cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
        FORE(i,p) cnt[0] += ((*i%v2) > s2);// && (*i%v1) < s1;
//        debug(cnt[0]);
        assert(cnt[0] == 2*n);
    } 
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(8);
    cin >> T;
    FOR(cas,1,T) {
//        cout << cas << "/" << T << " " << n << endl;
        p.clear();
        //in
        cin >> n;
        REP(i,4*n) {
            int x,y;
            cin >> x >> y;
            p.PB(P(x,y));
        }
        //sol
        LD low = 0.86599128719654997l;
//        cout << val(low) << " " << val(low + 0.5*M_PI) << "??????????????????" << endl;
//        debug(val(0));
        if(val(low) > 0) low += 0.5l * M_PI;
        LD high = low + 0.5l * M_PI;
        if(val(low) != 0) {
            while(1) {
            LD mid = 0.5l * (low + high);
            int v = val(mid);
            if(v == 0) break;
            if(v < 0) low = mid;
            else high = mid;
            }
        }
        //out
        assert(val(last) == 0);
//        resA /= obrot;
//        resB /= obrot;
        P resC = resA + (resB - resA) * P(0,1);
        int cnt = 0;
//        FORE(i,p) *i /= obrot;
        FORE(i,p) if(wek(resA, resB, *i) > 0 && wek(resA, resC, *i) < 0) cnt++;
//        FORE(i,p) assert(abs(wek(resA,resC,*i)) > 1E-7);
//        cout << cnt << " " << n << endl;
//        assert(cnt == n);
        cout << "Case #" << cas << ": ";
        cout << resA.real() << " " << resA.imag() << " " << resB.real() << " " << resB.imag() << endl;
//        cout << cas << "/" << T << " " << n << endl;
    }
    return 0;
}


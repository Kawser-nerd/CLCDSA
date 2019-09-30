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
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<typename T1, typename T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { out << "(" << pair.FI << ", " << pair.SE << ")"; return out; }
#define MAXN 100007
typedef VI::iterator iter;

int T,n,d,K,a[MAXN][4],res,beg;
VI where[MAXN];

void sol(int aa,int bb){
    if(bb-aa+1 > res) {
        res = bb-aa+1;
        beg = aa;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin >> T;
    FOR(cas,1,T) {
        REP(i,MAXN) where[i].clear();
        res = beg = 0;
        //in
        cin >> n >> d >> K;
        REP(i,n) REP(j,d) cin >> a[i][j];
        REP(i,n) REP(j,d) {
            bool ok = true;
            REP(jj,j) if(a[i][j] == a[i][jj]) ok = false;
            if(ok) where[a[i][j]].PB(i);
        }
        REP(i,MAXN) where[i].PB(INF);
        //sol
        REP(i,n) REP(j,d) {
            int v = a[i][j];
            iter take = lower_bound(ALL(where[v]), i);
            assert(*take == i);
            while(*(take+1) == (*take)+1) ++take;
            if((*take)+1 < n) REP(jj,d) {
                iter take1 = take;
                int next = (*take1)+1;
                int vv = a[next][jj];
                iter take2 = lower_bound(ALL(where[vv]), next);
                assert(*take2 == next);
                int k;
                for(k=next; k<=n-1; k++) {
                    if(*take1  < k) ++take1;
                    if(*take2 < k) ++take2;
                    if(*take1 != k && *take2 != k) {sol(i,k-1); break;}
                }
                if(k == n) sol(i, n-1);
            } else sol(i,*take);
        }
        //out
        cout << "Case #" << cas << ": ";
        cout << beg << " " << beg+res-1 << endl;
    }
    return 0;
}


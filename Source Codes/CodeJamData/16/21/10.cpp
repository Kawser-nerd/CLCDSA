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
#define debug(x) //{cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) //{{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

string digs[10] = {"ZERO","ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


void solve(int tc) {
    cout << "Case #" << tc << ": ";
    map<char, int> M;
    string S;
    cin >> S;
    for (char c : S) M[c]++;
    set<int> r;
    REP(i,10) r.insert(i);
    VI cnt(10);
    while(SZ(r) > 0) {
        int val = -1;
        char c;
        for (c = 'A'; c <= 'Z'; ++c) {
            int no = 0;
            for (int i : r) for (char d : digs[i]) if (d == c) {
                ++no;
                val = i;
            }
           if (no == 1) break;
        }
        debugv(r);
        debug(MP(val,c));
        cnt[val] += M[c];
        for (char d : digs[val]) M[d] -= cnt[val];
        r.erase(r.find(val));
    }
    REP(i, 10) REP(j, cnt[i]) cout << i;
    cout << endl;
    for (auto m : M) assert(m.Y == 0);
}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}


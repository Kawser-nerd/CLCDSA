// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
// BEGIN CUT HERE
#define DEBUG(var) { cout << #var << ": " << (var) << endl; }
template <class T> ostream& operator << (ostream &os, const vector<T> &temp) { os << "[ "; for (unsigned int i=0; i<temp.size(); ++i) os << (i?", ":"") << temp[i]; os << " ]"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const set<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const multiset<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const pair<S,T> &a) { os << "(" << a.first << "," << a.second << ")"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const map<S,T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (it->first) << "->" << it->second; os << " }"; return os; } // DEBUG
// END CUT HERE
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int N;
vector< vector<int> > dobre;
map< vector<int>, int> memo;
map< vector<int>, vector<int> > memo2;
vector<int> pozeral;

bool je_dobre(const vector<int> &hu) {
    REP(k,SIZE(hu)) REP(j,k) REP(i,j) if (hu[i]>hu[j] && hu[j]>hu[k]) return false;
    return true;
}

bool consistent(const vector<int> &mam, const vector<int> &chcem) {
    REP(n,N) if (chcem[n]!=mam[n] && chcem[n]!=-1) return false;
    return true;
}

int get_worst_time(vector<int> known) {
    bool cons = false;
    REP(i,SIZE(dobre)) if (consistent(dobre[i],known)) { cons=true; break; }
    if (!cons) return 0;
    REP(i,SIZE(dobre)) if (dobre[i]==known) return 0;
    if (memo.count(known)) return memo[known];
    int &res = memo[known];
    res = 9876543;
    vector<bool> unused(N,true);
    REP(n,N) if (known[n]!=-1) unused[known[n]]=false;
    vector<int> canuse;
    REP(n,N) if (n>0 && unused[n]) canuse.push_back(n);
    REP(n,N) if (known[n]==-1) {
        int curr = 1;
        REP(i,SIZE(canuse)) { known[n]=canuse[i]; curr=max(curr,1+get_worst_time(known)); known[n]=-1; }
        res = min(res,curr);
    }
    // DEBUG
    // cout << "get_worst_time " << known << " return " << res << endl;
    return res;
}

vector<int> get_optimal_moves(vector<int> known) {
    // DEBUG(known);
    vector<int> result2;
    bool cons = false;
    REP(i,SIZE(dobre)) if (consistent(dobre[i],known)) { cons=true; break; }
    if (!cons) return result2;
    REP(i,SIZE(dobre)) if (dobre[i]==known) return result2;
    if (memo2.count(known)) return memo2[known];
    vector<int> &result = memo2[known];
    int res = 9876543;
    vector<bool> unused(N,true);
    REP(n,N) if (known[n]!=-1) unused[known[n]]=false;
    vector<int> canuse;
    REP(n,N) if (n>0 && unused[n]) canuse.push_back(n);
    REP(n,N) if (known[n]==-1) {
        int curr = 1;
        REP(i,SIZE(canuse)) { known[n]=canuse[i]; curr=max(curr,1+get_worst_time(known)); known[n]=-1; }
        if (curr < res) result.clear();
        if (curr <= res) { res=curr; result.push_back(n); }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    FOR(t,1,T) {
        cin >> N;
        pozeral.resize(N);
        REP(n,N) { cin >> pozeral[n]; --pozeral[n]; }

        dobre.clear();
        vector<int> mam(N);
        REP(n,N) mam[n]=n;
        do { if (je_dobre(mam)) dobre.push_back(mam); } while (next_permutation(mam.begin(),mam.end()));

        vector<int> answer;
        REP(n,N) mam[n]=n;
        do { 
            if (mam[pozeral[N-1]] != 0) continue;
            vector<int> known(N,-1);
            bool ok = true;
            REP(n,N) {
                bool cons = false;
                REP(i,SIZE(dobre)) if (consistent(dobre[i],known)) { cons=true; break; }
                if (!cons) { ok=false; break; }
                vector<int> OM = get_optimal_moves(known);
                bool ma=false;
                REP(i,SIZE(OM)) if (OM[i]==pozeral[n]) ma=true;
                if (!ma) { ok=false; break; }
                known[pozeral[n]] = mam[pozeral[n]];
            }
            if (ok) answer = mam;
        } while (next_permutation(mam.begin(),mam.end()));
        printf("Case #%d:",t);
        REP(n,N) printf(" %d",answer[n]+1);
        printf("\n");
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

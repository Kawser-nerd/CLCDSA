// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define CLEAR(t) memset((t),0,sizeof(t))
// BEGIN CUT HERE
#define DEBUG(var) { cout << #var << ": " << (var) << endl; }
template <class T> ostream& operator << (ostream &os, const vector<T> &temp) { os << "[ "; for (unsigned int i=0; i<temp.size(); ++i) os << (i?", ":"") << temp[i]; os << " ]"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const set<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const multiset<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const pair<S,T> &a) { os << "(" << a.first << "," << a.second << ")"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const map<S,T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (it->first) << "->" << it->second; os << " }"; return os; } // DEBUG
// END CUT HERE
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

#include <tr1/unordered_map>
#define MOD 10007
#define LAST(seq,col) ((seq) & 31)
#define FIRST(seq,col) ((seq) >> (5*((col)-1)))

std::tr1::unordered_map<long long, int > M[11];
// map<long long, int > M[11];
int rrr[12];
int R, C;
int A[52][52];
int hlp[52];
int answer[2][53000000];

/*
inline long long encode(const vector<int> &co) {
  long long res = 0;
  for (int i=0; i<SIZE(co); ++i) res <<= 5, res += co[i];
  return res;
}

void skus(int c, int x, int y) {
  tmp[x] = y;
  if (x < c-1) for (int yy=y; yy<26; ++yy) skus(c,x+1,yy); else M[c][encode(tmp)] = rrr++;
}
*/

string pretty(long long seq, int c) {
  string res; 
  REP(i,c) { res += char('a' + (seq & 31)); seq >>= 5; }
  return res;
}

int main() {
  // FOR(c,1,6) { rrr=0; tmp.clear(); tmp.resize(c); skus(c,0,0); }
  int TTT;
  cin >> TTT;
  FOR(ttt,1,TTT) {
    cin >> R >> C;
    string line;
    REP(r,R) {
      cin >> line;
      REP(c,C) if (line[c]=='.') A[r][c]=-1; else A[r][c]=line[c]-'a';
    }
    if (rrr[C]==0) {
      M[C][0] = 0;
      rrr[C] = 1;
    }
    int Z = SIZE( M[C] );
    REP(z,Z) answer[0][z] = 0;
    answer[0][0] = 1;
    int cur=0, prev, total;
    for (int r=0; r<R; ++r) for (int c=0; c<C; ++c) {
      total = 0;
      cur = 1-cur;
      prev = 1-cur;
      
      // REP(z,SIZE(M[C])) answer[cur][z] = 0;
      // FOREACH(it,M[C]) answer[cur][it->second] = 0;
      CLEAR(answer[cur]);
      
      std::tr1::unordered_map<long long, int > todo;
      FOREACH(it,M[C]) {
        long long seq = it->first;
        int seq_id = it->second;
        if (answer[prev][seq_id] == 0) continue;
        // cout << "processing " << pretty(seq,C) << endl;
        int top = LAST(seq,C), left = FIRST(seq,C);
        if (c==0) left = 0;
        if (A[r][c] != -1) {
          if (A[r][c] < top) continue;
          if (A[r][c] < left) continue;
        }
        int start, end;
        start = max(top,left);
        end = 25;
        if (A[r][c] != -1) start = end = A[r][c];
        for (int co=start; co<=end; ++co) {
          long long nseq = (seq >> 5) | ( co << 5*(C-1) );
          int nid;
          if (M[C].count(nseq)) {
            nid = M[C][nseq];
          } else {
            if (todo.count(nseq)) {
              nid = todo[nseq];
            } else {
              todo[ nseq ] = rrr[C]++;
              nid = todo[nseq];
            }
          }
          // cout << "adding " << answer[prev][seq_id] << " to answer for " << pretty(nseq,C) << " debug " << nid << " " << endl;
          // DEBUG(answer[cur][nid]);
          answer[cur][nid] += answer[prev][seq_id];
          answer[cur][nid] %= MOD;
          // DEBUG(answer[cur][nid]);
          // DEBUG(answer[cur][2]);
          total += answer[prev][seq_id];
          total %= MOD;
        }
      }
      FOREACH(it,todo) M[C][it->first] = it->second;
      // DEBUG(M[C].size());
      int test = 0;
      FOREACH(it,M[C]) {
        test += answer[cur][it->second];
        // if (answer[cur][it->second]) cout << pretty(it->first,C) << ": " << answer[cur][it->second] << endl;
      }
      // DEBUG(test);
      // cout << r << " " << c << ": " << total << endl;
    }
    cout << "Case #" << ttt << ": " << total << endl;
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

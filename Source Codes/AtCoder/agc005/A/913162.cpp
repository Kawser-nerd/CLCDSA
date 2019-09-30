#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<char> vc;
typedef vector<vector<char> > vvc;
typedef vector<double> vd;
typedef vector<vector<double> > vvd;
template<class T> using vv=vector<vector< T > >;
typedef deque<int> di;
typedef deque<deque<int> > ddi;
typedef deque<bool> db;
typedef deque<deque<bool> > ddb;

// cout pair
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {
  s << p.first << " " << p.second << "\n"; return s;
}

// cout vector<pair>
template<typename T1, typename T2> ostream& operator<<(ostream& s, const vector<pair<T1, T2> >& vp) {
  int len = vp.size(); s << "\n";
  for (int i = 0; i < len; ++i) { s << vp[i]; }
    s << "\n"; return s;
}

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout deque
template<typename T> ostream& operator<<(ostream& s, const deque<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}

// cout 2-dimentional deque
template<typename T> ostream& operator<<(ostream& s, const deque< deque<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}

int main() {
  string x;
  cin >> x;
  int len = x.length();
  int ans = len;
  /*
  rep (i, len) {
    if (x[i] =='S') {
      tmp = i;
      break;
    }
  }
  x = x.substr(tmp, len - tmp);
  len = x.length();
  */
  deque<pii> st;
  int current = 'S';
  map<char, int> stlen;
  rep (i, len) {
    if (current == 'T' && x[i] == 'S') {
      st.push_back(mp(stlen['S'], stlen['T']));
      stlen['S'] = stlen['T'] = 0;
    }
    stlen[x[i]] += 1;
    current = x[i];
  }
  st.push_back(mp(stlen['S'], stlen['T']));
  int stsize = st.size();
  rep (i, stsize) {
    ans -= 2 * min(st[i].fst, st[i].snd);
    if (i < stsize && st[i].fst > st[i].snd) {
      st[i+1].fst += (st[i].fst - st[i].snd);
    }
  }
  printf("%d\n", ans);

  return 0;
}
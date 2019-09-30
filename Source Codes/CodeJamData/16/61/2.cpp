#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
#define LL long long
#define int LL
#define st first
#define nd second
#define FI st
#define SE nd
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i, n) FOR(i, 0, (int)(n)-1)
#define R(i,n) REP(i,n)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int,int>
#define VI vector<int>
template<class C4> void mini(C4&a4, C4 b4){a4=min(a4,b4);}
template<class C4> void maxi(C4&a4, C4 b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char* sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char* sdbg, TH h, TA... t){
  while(*sdbg!=',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}

template<class L, class R> ostream& operator<<(ostream& os, pair<L, R> pr) {
  return os << "(" << pr.first << ", " << pr.second << ")";
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for(auto vv : V) os << vv << ","; return os << "]";
}

using LD = long double;

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif



struct Test {
  using T = __int128_t;
  string s;
  vector<vector<pair<int, int>>> adj;

  int addAdj() {
    int id = SZ(adj);
    adj.emplace_back();
    return id;
  }

  void process(int L, int R, int start, int end) {
    string sss;
    for (int i = L; i < R; i++) { sss += s[i]; }
    debug(L, R, start, end, sss);

    int ptr = L;
    while (ptr < R) {
      debug(ptr);
      int x = addAdj();

      if (isdigit(s[ptr])) {
        adj[start].emplace_back(s[ptr] - '0', x);
        start = x;
        ptr++;
      } else {
        assert(s[ptr] == '(');
        int c = 1, cptr = ptr + 1;
        while (c) {
          if (s[cptr] == '(') { c++; }
          if (s[cptr] == ')') { c--; }
          cptr++;
        }

        debug(cptr);

        if (cptr < SZ(s) && s[cptr] == '*') {
          process(ptr + 1, cptr - 1, x, x);
          adj[start].emplace_back(-1, x);
          start = x;
          ptr = cptr + 1;
        } else {
          debug("!!", start, end, x);
          int last = ptr, pos = last, d = 0;
          while (pos < cptr) {
            if ((s[pos] == '|' || s[pos] == ')') && d == 1) {
              process(last + 1, pos, start, x);
              last = pos;
            }

            if (s[pos] == '(') { d++; }
            if (s[pos] == ')') { d--; }
            pos++;
          }

          start = x;
          ptr = cptr;
        }
      }
    }

    adj[start].emplace_back(-1, end);
  }

  T LX, RX;
  LL result = 0;

  void extend(vector<bool> &P) {
    queue<int> Q;
    for (int i = 0; i < SZ(adj); i++) { if (P[i]) { Q.push(i); } }

    vector<bool> R = P;

    while (!Q.empty()) {
      int t = Q.front(); Q.pop();
      for (auto PP : adj[t]) {
        if (PP.first != -1) { continue; }
        if (!R[PP.second]) {
          R[PP.second] = true;
          Q.push(PP.second);
        }
      }
    }

    P = R;
  }

  void extend(LL &mask) {
    vector<bool> P(SZ(adj));
    for (int i = 0; i < SZ(adj); i++) { P[i] = (mask & (1LL << i)); }
    extend(P);
    mask = 0;
    for (int i = 0; i < SZ(adj); i++) { if (P[i]) { mask |= (1LL << i); } }
  }


  map<pair<LL, int>, LL> memo;
  LL getAtLen(LL mask, int len) {
    extend(mask);
    if (len == 0) {
      if (mask & 2) { return 1; }
      return 0;
    }

    auto PM = make_pair(mask, len);
    if (memo.count(PM)) { return memo[PM]; }

    LL res = 0;

    for (int d = 0; d < 10; d++) {
      LL nmask = 0;
      for (int i = 0; i < SZ(adj); i++) {
        if (mask & (1LL << i)) {
          for (auto P : adj[i]) {
            if (P.first != d) { continue; }
            nmask |= (1LL << P.second);
          }
        }
      }

  
      res += getAtLen(nmask, len - 1);
    }

    return memo[PM] = res;

  }


  void processPref(string str, int len) {
    debug(str, len);
    vector<bool> possible(SZ(adj));
    possible[0] = true;
    extend(possible);

    for (char ch : str) {
      int d = ch - '0';
      vector<bool> npossible(SZ(adj));

      for (int i = 0; i < SZ(adj); i++) {
        if (!possible[i]) { continue; }
        for (auto P : adj[i]) {
          if (P.first != d) { continue; }
          npossible[P.second] = true;
        }
      }

      possible = npossible;
      extend(possible);
    }

    LL mask = 0;
    for (int i = 0; i < SZ(adj); i++) {
      if (possible[i]) { mask |= (1LL << i); }
    }

    result += getAtLen(mask, len);

  }

  void processMult(T L, T R, T base, T cur, string str, int len) {
    if (L <= cur && cur + base * 10 <= R) {
      processPref(str, len);
      return;
    }

    for (int i = 0; i < 10; i++) {
      T x = cur + base * i;
      if (x + base <= L) { continue; }
      if (x > R) { continue; }
      processMult(L, R, base / 10, x, str + (i || (str != "") ? to_string(i) : ""), len - 1);
    }
  }


  void run(int testid) {
    debug(testid);
    LL __LX, __RX;
    cin >> __LX >> __RX;
    LX = __LX;
    RX = __RX;
    cin >> s;
    debug(s);
    adj.emplace_back();
    adj.emplace_back();
    process(0, SZ(s), 0, 1);

    for (int i = 0; i < SZ(adj); i++) {
      cerr << i << ": ";
      for (auto P : adj[i]) {
        cerr << "(" << P.first << "," << P.second << ") ";
      }
      cerr << "\n";
    }


    T mult = 1;
    int len = 0;
    while (mult <= RX) {
      mult *= 10;
      len++;
    }
    debug(len);

    processMult(LX, RX, mult, 0, "", len + 1);


    cout << "Case #" << testid << ": " << result << "\n";;
  }
};


#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    Test test;
    test.run(i);
  }

  return 0;
}

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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

using LD = long double;

struct Test {
  vector<int> parent, treeSize;
  vector<vector<int>> children;
  //vector<LD> logTopoOrders;
  vector<LD> logFacts;
  vector<string> words;
  int N, M;
  string courses;


  /*LD logFact(LL n, LL k) {
    return logFacts[n] - logFacts[k] - logFacts[n - k];
  }*/

  void makeDp(int vert) {
    //logTopoOrders[vert] = 0;
    treeSize[vert] = 1;

    for (int ch : children[vert]) {
      makeDp(ch);
      //logTopoOrders[vert] += logTopoOrders[ch];
      treeSize[vert] += treeSize[ch];
    }

    debug(vert, treeSize[vert]);

    /*int S = treeSize[vert] - 1;
    for (int ch : children) {
      logTopoOrders[vert] += logFacts(S, treeSize[ch]);
      S -= treeSize[ch];
    }*/
  }

  string genRandomString() {
    string str;
    vector<int> current{0};

    for (int i = 0; i <= N; i++) {
      int maxRange = 0;
      for (int j = 0; j < SZ(current); j++) {
        maxRange += treeSize[current[j]];
        //debug(i, current, j, current[j], maxRange);
      }

      int what = rand() % maxRange;
      //debug(what, maxRange);
      int chosen = -1;
      for (int j = 0; j < SZ(current); j++) {
        if (what < treeSize[current[j]]) {
          chosen = j;
          break;
        } else {
          what -= treeSize[current[j]];
        }
      }

      assert(chosen >= 0);
      chosen = current[chosen];
      str += courses[chosen];
      current.erase(find(ALL(current), chosen));
      for (int ch : children[chosen]) {
        current.push_back(ch);
      }
    }

    //debug(str);

    return str;
  }

  void run(int testid) {
    cin >> N;
    parent.resize(N + 1);
    children.resize(N + 1);
    treeSize.resize(N + 1);
    logFacts.resize(N + 50);
    //logTopoOrders.resize(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> parent[i];
      children[parent[i]].push_back(i);
    }

    logFacts[0] = 0;
    for (int i = 1; i < N + 50; i++) {
      logFacts[i] = logFacts[i - 1] + log(i);
    }

    cin >> courses;
    courses = "^" + courses;

    cin >> M;
    for (int i = 0; i < M; i++) {
      string s; 
      cin >> s;
      words.push_back(s);
    }

    makeDp(0);

    const int cntTries = 20000;
    vector<int> result(M);

    for (int tries = 0; tries < cntTries; tries++) {
      string str = genRandomString();

      for (int i = 0; i < M; i++) {
        if (str.find(words[i]) != string::npos) {
          result[i]++;
        }
      }
    }


    cout << "Case #" << testid << ":";
    for (int i = 0; i < M; i++) {
      cout << " " << (LD)result[i] / cntTries;
    }
    cout << endl;
  }
};


#undef int
int main(){
#define int LL
  srand(3141579);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cerr << i << endl;
    Test test;
    test.run(i);
  }

  return 0;
}

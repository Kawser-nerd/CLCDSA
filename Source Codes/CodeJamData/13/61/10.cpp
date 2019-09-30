#include <iostream>
#include <set>

using namespace std;

void doit(int casenum) {
  set<pair<int, int> > f, fe, fl, fm;
  int C, X, N;
  cin >> C >> X >> N;
  for(unsigned i = 0; i < C; ++i) {
    int a, b, t;
    cin >> a >> b >> t;
    --a; --b;
    int l = (b + N - a) % N;
    fe.insert(make_pair(a, t));
    fl.insert(make_pair(b, t + l));
    f.insert(make_pair(b, t + l));
    for(int x = a; x != b; x = (x + 1) % N, ++t) {
      f.insert(make_pair(x, t));
     // cerr << "c " << x << " " << t << endl;
      fm.insert(make_pair((x + 1) % N, t));
    }
  }
  
  int ml = 0;
  for(unsigned i = 0; i < N; ++i) {
    for(unsigned j = 0; j < X; ++j) {
      if(fe.find(make_pair(i,j)) != fe.end()) continue;
      int pos = i;
      int t = j;
      int l = 0;
      for(;;) {
        if(t > X) break;
        if(f.find(make_pair(pos, t)) != f.end()) break;
        if(fl.find(make_pair(pos, t)) == fl.end()) {
          
          if(l > ml)
         // cerr << i << " " << j << " " << l << endl;
          ml = max(l, ml);
        }
        if(fm.find(make_pair(pos, t)) != fm.end()) {
         // cerr << pos << " " << t << " cannot move back" << endl;
          break;
        }
        l++;
        t++;
        pos = (pos + N - 1) % N;
      }
    }
    
  }
  cout << "Case #" << casenum << ": " << ml << endl;
}

int main(int argc, char **argv) {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i)
      doit(i);
    return 0;
}

#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#include <tuple>

#define MP(a,b) make_pair(a,b)

int main() {
  using namespace std;
  int R, C;
  cin >> R >> C;
  pair<int, int> s,g;
  cin >> s.first >> s.second;
  cin >> g.first >> g.second;
  s.first--;
  s.second--;
  g.first--;
  g.second--;
  vector< vector< pair<int , char> > > m = vector< vector< pair<int, char> > >(R, vector< pair<int, char> >(C));

  for(auto &r: m) {
    for(auto &c: r) {
      cin >> c.second;
      c.first = -1;
    }
  }

  deque< pair<int, pair< int, int> > > q;
  q.push_back(make_pair(0, s));
  m[s.first][s.second].first = 0;


  while(!q.empty()) {
    int len;
    pair<int, int> pos;
    tie(len, pos) = q.front();
    q.pop_front();
    //cout << "(" << pos.first << "," << pos.second << ") len:" << len << endl;

    if(pos == g) {
      cout << len << endl;
      return 0;
    } else {
      int l;
      char c;
      tie(l, c) = m[pos.first][pos.second];
      if(l < 0) continue;
      if(c == '#') continue;
      else if(c == '.' ) {

        for(int i = 0; i < 4; i++) {
          pair<int,int> n;
          if(i < 2) {
            n = make_pair(2 * i - 1 + pos.first, pos.second);
          } else {
            n = make_pair(pos.first, 2 * i - 5 +  pos.second);
          }
          int x, y;
          tie(x, y) = n;
          if(x < 0 || x >= R || y < 0 || y >= C) continue;

          if(m[n.first][n.second].first >= 0) continue;
          m[n.first][n.second].first = len + 1;
          q.push_back(make_pair(len + 1, n));
        }
      }
    }
  }

  cout << "ERROR" << endl;
}
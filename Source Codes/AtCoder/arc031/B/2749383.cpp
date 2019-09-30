#include <iostream>
#include <vector>
#include <utility>
int main() {
  using namespace std;

  vector< vector<char> > m = vector<vector<char> >(10, vector<char>(10));
  for(auto &x: m) {
    for(auto &i: x) {
      cin >> i;
    }
  }

  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      vector< vector<char> > tmp = m;
      tmp[i][j] = 'o';
      vector< pair<int, int> > r;
      r.push_back(make_pair(i,j));

      while(!r.empty()) {
        auto pos = r.back();
        r.pop_back();
        auto& c = tmp[pos.first][pos.second];
        //cout << pos.first << " " << pos.second <<" " << c <<endl;
        if(c == 'o') {
          c = 'x';
          for(int i = 0; i < 4; i++) {
            int x, y;
            if(i < 2) {
              x = pos.first + (2 * i - 1);
              y = pos.second;
            } else {
              x = pos.first;
              y = pos.second + (2 * i - 5);
            }
            if(x < 0 || x >= 10 || y < 0 || y >= 10) continue;
            r.push_back(make_pair(x, y));
          }
        }
      }

      for(auto x: tmp) {
        for(auto i: x) {
          if(i == 'o') goto next;
        }
      }
      cout << "YES" << endl;
      return 0;
    next:
      ;
    }
  }
  cout << "NO" << endl;
}
#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define rep(i, n)      for (int i=0; i<int(n); i++)
#define rep3(i, s, n)  for (int i=int(s); i<int(n); i++)
#define rev_rep(i, n)  for (int i=int(n)-1; i>=0; i-=1)

#define MAX_N 100100
#define INF 1145141919

int N;
vector< pair<int, int> > s;
int memo[MAX_N];

int f(int x) {
  //cout << "f("<<x<<")\n";
  if (memo[x] != 0) return memo[x];
  int ans = 1;
  //vector< pair<int, int> > v;
  rep3(i, x+1, min(N, x+1500)) {
    /*
    bool ng = false;
    for (auto t : v) {
      if (t.first <= s[i].first && t.second <= s[i].second) {
        ng = true;
        break;
      }
    }
    if (ng) continue;
    */
    if (s[i].first > s[x].first && s[i].second > s[x].second) {
      ans = max(ans, f(i) + 1);
      // v.push_back(s[i]);
      // if (v.size() >= 3) break;
    }
  }
  memo[x] = ans;
  return ans;
}

int main() {
  cin >> N;
  rep(i, N) {
    int w, h;
    cin >> w >> h;
    s.push_back( make_pair(w, h) );
  }

  sort(s.begin(), s.end(), [](auto &left, auto &right) {
    return left.second < right.second;
    int max_l = min(left.first, left.second);
    int max_r = min(right.first, right.second);
    //return max_l == max_r ? (left.first + left.second) < (right.first + right.second) : max_l < max_r;
  });
  //rep(i, N) cout << s[i].first << " "<<s[i].second <<"\n";
  int ans = 0;
  rev_rep(i, N) ans = max(ans, f(i));
  cout << ans << "\n";
  return 0;
}
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long int lli;
const lli mod = 1000000007L;
int main() {
  int n; cin >>n;
  vector<string> add_chs;
  add_chs.push_back("A");
  add_chs.push_back("C");
  add_chs.push_back("G");
  add_chs.push_back("T");
  map<string, lli> memo;
  memo[""] = 1;
  for (int i=0; i < n; i++) {
    map<string, lli> new_memo;
    for (auto it = memo.begin(); it != memo.end(); it++) {
      string tmp = it->first;
      lli num = it->second;

      for (int j = 0; j < add_chs.size(); j++) {
        string next = tmp + add_chs[j];
        if (next.size() == 3 && next == "AGC") {
          continue;
        }
        if (next.size() == 3) {
          if (next[2] == 'C') {
            if (next[0] == 'A' && next[1] == 'G') { continue; }
            if (next[0] == 'G' && next[1] == 'A') { continue; }
          }
          if (next[2] == 'G' && next[0] == 'A' && next[1] == 'C') {continue;}
        }
        if (next.size() == 4) {
          if (next[3] == 'C') {
            if (next[1] == 'A' && next[2] == 'G') { continue; }
            if (next[0] == 'A' && next[2] == 'G') { continue; }
            if (next[1] == 'G' && next[2] == 'A') { continue; }
            if (next[0] == 'A' && next[1] == 'G') { continue; }
          }
          if (next[3] == 'G' && next[1] == 'A' && next[2] == 'C') {continue;}
        }
        if (next.size() == 4) {
          next = next.substr(1, 3);
        }
        if (new_memo.find(next) == new_memo.end()) {
          new_memo[next] = 0;
        }
        new_memo[next] = (new_memo[next] + num) % mod;
      }
    }
    memo = new_memo;
  }

  lli ans = 0;
  for (auto it = memo.begin(); it != memo.end(); it++) {
    ans = (ans + it->second) % mod;
  }

  cout << ans << endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <deque>
#include <string>

//not AC
using namespace std;


bool canMoveLessThan(string s, deque<char> t, int k) {
  for(int i = 0; i < s.size(); i++) {
    for(int j = 0; j < t.size(); j++) {
      if(s[i] == t[j]) {
        t.erase(t.begin() + j, t.begin() + j + 1);
        goto next;
      }
    }
    k--;
    if(k < 0) return false;
  next:
    ;
  }

  return true;
}

int same(string& s, string& t) {
  int out = 0;
  for(int i = 0; i < t.size() && i < s.size(); i++) {
    if(s[i] != t[i]) out++;
  }
  return out;
}

int main() {
  string S;
  int N,K;
  string out = "";
  cin >> N >> K >> S;

  deque<char> pool;
  for(auto x: S) pool.push_back(x);
  sort(pool.begin(), pool.end());

  while(out.size() < S.size()) {
    for(int i = 0; i < pool.size(); i++) {
      out.push_back(pool[i]);
      pool.erase(pool.begin() + i,pool.begin() + i + 1);
      int l = same(S, out);
      if(canMoveLessThan(S.substr(out.size()), pool, K - l)) {
        break;
      } else {
        pool.insert(pool.begin() + i, out.back());
        out.pop_back();
      }
    }
  }
  cout << out << endl;
}
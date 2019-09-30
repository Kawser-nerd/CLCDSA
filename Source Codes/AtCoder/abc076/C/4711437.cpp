#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[]) {
  string S, T;
  cin >> S >> T;
  if (T.size() > S.size()) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  vector<string> ans;
  for (size_t i = 0; i < S.size() - T.size() + 1; i++) {
    string temp = S.substr(0, i);
    bool is_all_ok = true;
    for (size_t j = 0; j < T.size(); j++) {
      if (S[i + j] == T[j] || S[i + j] == '?') {
        temp.push_back(T[j]);
      } else
        is_all_ok = false;
    }
    if (is_all_ok) {
      string sub = S.substr(i + T.size(), S.size() - T.size());
      temp += sub;
      ans.push_back(temp);
    }
  }
  if (ans.empty()) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  string out = "|";
  for (size_t i = 0; i < ans.size(); i++) {
    for (size_t j = 0; j < ans[i].size(); j++) {
      if (ans[i][j] == '?') ans[i][j] = 'a';
    }
    if (out > ans[i]) out = ans[i];
  }
  cout << out << endl;

  return 0;
}
#include <iostream>
#include <set>
using namespace std;

int main() {
  int N;
  cin >> N;
  string W;
  set<string> words;
  cin >> W;
  char start{W[W.length() - 1]};
  words.insert(W);
  bool ans{true};
  for (int i{1}; i < N; ++i) {
    cin >> W;
    if (W[0] != start || words.find(W) != words.end()) {
      ans = false;
      break;
    }
    start = W[W.length() - 1];
    words.insert(W);
  }

  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
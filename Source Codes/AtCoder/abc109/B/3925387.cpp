#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<string> W(N);
  for (int i = 0; i < N; i++)
    cin >> W[i];

  auto b = W[0].back();
  for (int i = 1; i < N; i++) {
    if (b == W[i].front()) {
      b = W[i].back();
    } else {
      cout << "No" << endl;
      return 0;
    }
  }

  int len = W.size();
  sort(W.begin(), W.end());
  W.erase(unique(W.begin(), W.end()), W.end());
  if (len != W.size()) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;

  return 0;
}
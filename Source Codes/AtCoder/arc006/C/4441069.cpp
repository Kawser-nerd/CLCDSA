#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> piles;
  for (int i{}; i < N; ++i) {
    int w;
    cin >> w;
    for (auto &pile : piles) {
      if (pile >= w) {
        pile = w;
        goto NEXT;
      }
    }
    piles.push_back(w);
    NEXT:
    sort(piles.begin(), piles.end());
  }

  cout << piles.size() << endl;
  return 0;
}
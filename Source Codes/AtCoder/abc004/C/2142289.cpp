#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> map) {
  for (int i = 0; i < 6; i++) {
    cout << map[i];
  }
  cout << endl;
}
int main() {
  vector<int> card{1, 2, 3, 4, 5, 6};
  int N, mod;
  cin >> N;
  for (int i = 0; i < N; i++) {
    mod = i % 5;
    swap(card[mod], card[mod + 1]);
  }
  print(card);
  return 0;
}
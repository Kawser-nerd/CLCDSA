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
  int N, tmp;
  cin >> N;
  tmp = (N / 5) % 6;
  for (int i = 0; i < tmp; i++) {
    for (int j = 0; j < 5; j++) {
      swap(card[j], card[j + 1]);
    }
  }
  tmp = N % 5;
  for (int i = 0; i < tmp; i++) {
    swap(card[i], card[i + 1]);
  }
  print(card);
}
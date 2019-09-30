#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S[100];
  for (auto i = 0; i < N; i++) {
    cin >> S[i];
  }
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < N; j++) {
      cout << S[N-1-j][i];
    }
    cout << endl;
  }
}
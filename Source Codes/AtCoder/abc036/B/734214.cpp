#include <iostream>

using namespace std;

char BOARD[51][51];

int main() {

  int N;
  cin >> N;

  for (int i=1; i<=N; ++i) {
    for (int j=1; j<=N; ++j) {
      cin >> BOARD[i][j];
    }
  }

  for (int j=1; j<=N; ++j) {
    for (int i=N; 1<=i; --i) {
      cout << BOARD[i][j];
    }
    cout << endl;
  }

  return 0;
}
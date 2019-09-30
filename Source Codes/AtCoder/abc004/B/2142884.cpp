#include <iostream>
#include <vector>
using namespace std;
#define print(var) cout << var << endl
int main() {
  vector<vector<char>> map(4, vector<char>(4, '_'));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> map[i][j];
    }
  }
  for (int i = 3; i >= 0; i--) {
    for (int j = 3; j >= 0; j--) {
      cout << map[i][j] << ' ';
    }
    cout << endl;
  }
}
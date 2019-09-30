#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int N, s, min = numeric_limits<int>::max();
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    if (s < min) {
      min = s;
    }
  }
  cout << min << endl;
}
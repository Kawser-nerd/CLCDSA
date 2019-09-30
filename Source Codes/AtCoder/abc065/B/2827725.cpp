#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int a[100001];
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  //cout << "==============" << endl;
  int count = 0;
  int next_index = 1;
  for (int i = 0; i < N; i++) {
    count++;
    if (a[next_index] == 2) {
      cout << count << endl;
      return 0;
    }
    next_index = a[next_index];
  }
  cout << -1 << endl;
}
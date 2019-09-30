#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a, before=0, cnt=0;
  for (int i=0; i<N; i++) {
    cin >> a;
    if (before == a) {
      cnt++;
      before = 0;
    } else {
      before = a;
    }
  }
  cout << cnt << endl;
  return 0;
}
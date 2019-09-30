#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  long long ans = 1;
  int M = 1000000000 + 7;
  for(int i = 1; i <= N; i++) {
    //ans = ans * i;
    ans = ans * i % M;
  }
  cout << ans % M << endl;
}
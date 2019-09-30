#include <algorithm>
#include <iostream>
#define ll long long;
using namespace std;

int cnt_digits(long long N) {
  int digits = 0;

  while (N > 0) {
    N /= 10;
    digits++;
  }
  return digits;
}

int main(){
  long long N;
  cin >> N;

  int ans = cnt_digits(N);

  for(long long A = 1LL; A * A <= N; ++A) {
    if(N % A != 0) continue;

    const long long B = N / A;

    const int cur=max(cnt_digits(A), cnt_digits(B));
    if(ans > cur){
      ans = cur;
    }
  }
  cout << ans << endl;
  return 0;
}
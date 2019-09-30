#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

long long dist(long long N) {
  ostringstream sout;
  sout << N;
  string s = sout.str();
  int a = atoi(s.substr(s.size()/2).c_str());
  reverse(s.begin(), s.end());
  int b = atoi(s.substr((s.size()+1)/2).c_str());
  if (a == 0 && b == 1) return 0;
  if (a == 0) return dist(N-1)+1;
  return a + (b<=1 ? 0 : b);
}

main() {
  long long T, N, prob=1;

  for (cin >> T; T--;) {
    cin >> N;
    long long ret = 0, d;
    for (d = 10; d <= N; d *= 10) {
      ret += dist(d-1)+1;
    }
    ret += dist(N);
    cout << "Case #" << prob++ << ": " << ret << endl;
  }
}

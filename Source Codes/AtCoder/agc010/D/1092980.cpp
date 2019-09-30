#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int simulator(vector<long>& cur) {
  long sum = 0;
  for(int i = 0; i < cur.size(); i++) {
    sum += cur[i] - 1;
  }
  bool win = (sum & 1);
  int odds = 0;
  for(int i = 0; i < cur.size(); i++) {
    if(cur[i] == 1) return win;
    if(cur[i] & 1) odds++;
  }
  // ???2???????????
  if(odds >= 2) return win;
  // ???1?????????????????
  if(odds >= 1 && win) return win;
  // ???1?????? ? ????????
  // TODO: ??: N = 2 ??????????????????????????
  for(int i = 0; i < cur.size(); i++) {
    if(cur[i] & 1) {
      cur[i]--;
      long gcd = cur[0];
      for(int i = 0; i < cur.size(); i++) {
        gcd = std::__gcd(cur[i], gcd);
      }
      for(int i = 0; i < cur.size(); i++) {
        cur[i] /= gcd;
      }
      return !simulator(cur);
      break;
    }
  }
}
int main() {
  int N;
  cin >> N;
  vector<long> a(N);
  long sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  cout << (simulator(a) ? "First" : "Second") << endl;
  return 0;
} ./Main.cpp:37:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.
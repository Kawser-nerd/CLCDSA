#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int cnt[4] = {};
  int N;
  cin >> N;
  string s;
  cin >> s;
  for (int i = 0; i < N; i++) {
    int tmp = (int)s[i] - '0';
    cnt[tmp - 1]++;
  }
  sort(cnt, cnt + 4);
  cout << cnt[3] << " " << cnt[0] << endl;
  return 0;
}
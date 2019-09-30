#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

int main() {
  int N;
  std::cin >> N;

  std::vector<int> a(N);
  std::map<int, int> mp;
  REP(i, N) {
    std::cin >> a[i];
    mp[a[i]] = 1;
  }

  int score=0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    it->second = score++;
  }
  
  REP(i, N) {
    std::cout << mp[a[i]] << std::endl;
  }

  return 0;
}
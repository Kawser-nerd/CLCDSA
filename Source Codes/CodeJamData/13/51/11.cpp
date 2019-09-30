/* Opgave: A */
// 7+8+7=22 includes
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>
#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm>

using namespace std;


long double tryLevel(const vector<long long>& v, int l) {
  long long spent = 0;
  long long reward = 0;
}
void doit (int t) {
  int N; long long B;
  cin >> B>> N;
  vector<long long> v(N);
  for(int i = 0; i < N; ++i) {
    cin >> v[i];
  }
  while(v.size() < 37)
    v.push_back(0);
  sort(v.begin(), v.end());
  long double m = 0.0;
  for(int cnt = 1; cnt <= 37; ++cnt) {
    for(int cnt2 = cnt; cnt2 <= 37; ++cnt2) {
      //if(cnt < 36 && v[cnt-1] == v[cnt]) continue;
      long long BB = B - cnt2 +cnt;
      for(int i = 0; i < cnt2; ++i) {
	BB -= v[cnt2-1] - v[i];
      }
      //for(int i = cnt; i < cnt2; ++i) {
      //BB -= 1+v[cnt2-1] - v[i];
      //}

      if(BB < 0) break;
      long long inc = BB / cnt2;
      if(cnt2 < 37) inc = min(inc, v[cnt2] - 1- v[cnt2-1]);
      if(inc < 0) continue;
      long long left = BB - inc * cnt2;
      assert(left >= 0);
      long long level = v[cnt2-1] + inc;
      long double p =  - B + left;
      for(int i = 0; i < cnt; ++i)
	p += 36.0L / cnt * (level - v[i]);
      //cerr << " " << cnt <<" " << level << " " << p << endl;
      long long tot = 0;
      for(int i = 0; i < cnt; ++i)
	tot += level - v[i];
      for(int i = cnt; i < cnt2; ++i)
	tot += level + 1 - v[i];
      tot += left;
      assert(tot == B);
      m = max(p, m);
    }
  }
  cout.precision(30);
  cout << "Case #" << t << ": " << m << endl;
}

int main () {
	int t;
	cin >> t; //scanf ("%d ", &t);
	for (int i = 0; i < t; i++) {
		doit (i+1);
	}
	return 0;
}
/* Opgave: A */

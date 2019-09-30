/* Opgave: D */
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

long double dp[2 << 20];

void doit (int t) {
  string s;
  cin >> s;
  int N = s.size();
  dp[(1 << N)-1] = 0;
  for(int i = (1 << N) - 2; i >= 0; --i) {
    long double p = 0.0L;
    for(int j = 0; j < N; ++j) {
      int P = N;
      int jj = j;
      while(i & (1 << (jj % N))) { jj++; P--; }
      p += P + dp[i | (1 << (jj % N))];
    }

    dp[i] = p / (long double)N;
  }
  unsigned v = 0;
  for(int i = 0; i < N; ++i) {
    if(s[i] == 'X') v |=  1 << i;
  }
  cout.precision(30);
  cout << "Case #" << t << ": " << dp[v] << endl;
}

int main () {
	int t;
	cin >> t; //scanf ("%d ", &t);
	for (int i = 0; i < t; i++) {
		doit (i+1);
	}
	return 0;
}
/* Opgave: D */

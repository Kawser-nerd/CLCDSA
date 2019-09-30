#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <numeric>
#include <complex>

using namespace std;

char like[2000][2000];
char malted[2000];
int like_malt[2000];

int main(void)
{
  int C;
  cin >> C;
  for (int c = 1; c <= C; c++) {
    memset(like, 2, sizeof(like));
    memset(malted, 0, sizeof(malted));
    memset(like_malt, -1, sizeof(like_malt));
    int N, M; cin >> N >> M;
    for (int m = 0; m < M; m++) {
      int T; cin >> T;
      int X, Y;
      for (int t = 0; t < T; t++) {
	cin >> X >> Y;
	like[m][X-1] = Y;
	if (Y == 1) like_malt[m] = X-1;
      }
    }
    bool change = true;
    while (change) {
      change = false;
      for (int m = 0; m < M; m++) {
	bool satisfied = false;
	for (int n = 0; n < N; n++)
	  if (like[m][n] == 0 && !malted[n]) {
	    satisfied = true;
	    break;
	  }
	if (!satisfied) {
	  int lm = like_malt[m];
	  if (lm >= 0) {
	    if (!malted[lm])
	      change = true;
	    malted[lm] = true;
	  }
	  else {
	    change = true;
	    goto out;
	  }
	} 
      }
    }
  out:;
    printf("Case #%d:", c);
    if (change) printf(" IMPOSSIBLE");
    else for (int i = 0; i < N; i++) printf(" %d", malted[i]);
    cout << endl;
  }
}

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

map < string, vector <string> > m;

int recurse(string s) {
  if (m[s].empty()) return 1;
  vector <int> sub;
  for (int i = 0; i < m[s].size(); i++)
    sub.push_back(recurse(m[s][i]));
  sort(sub.begin(), sub.end(), greater <int> ());
  int ans = sub.size() + 1;
  //cerr << s << endl;
  for (int i = 0; i < sub.size(); i++) {
    //cerr << sub[i] << endl;
    if (ans < sub[i] + i)
      ans = sub[i] + i;
  }
  return ans;
}

int main(void) {

  int C;
  cin >> C;
  for (int c = 1; c <= C; c++) {
    m.clear();
    int N;
    cin >> N;
    string want;
    for (int i = 0; i < N; i++) {
      string mix;
      cin >> mix;
      if (i == 0) want = mix;
      int M;
      cin >> M;
      for (int j = 0; j < M; j++) {
	string s;
	cin >> s;
	if (isupper(s[0]))
	  m[mix].push_back(s);
      }
    }
    printf("Case #%d: %d\n", c, recurse(want));
  }

}

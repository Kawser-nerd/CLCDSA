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

const int MOD = 10009;

set < pair <string, int> > seen;
map < pair <string, int>, int> store;
vector <string> words;

// note: if given an empty string, will return a vector with an empty
vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;
  
  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}

int memo(pair <string, int> key) {
  if (seen.find(key) != seen.end())
    return store[key];
  int ans = 0;
  string p = key.first; int k = key.second;
  if (k == 1) {
    for (int w = 0; w < words.size(); w++) {
      map <char, int> freqs;
      for (int i = 0; i < words[w].length(); i++)
	freqs[words[w][i]]++;
      int prod = 1;
      for (int j = 0; j < p.length(); j++)
	prod = prod * freqs[p[j]] % MOD;
      ans += prod;
    }
    ans %= MOD;
  }
  else {
    int e = p.length(), E = 1<<e;
    for (int mask = 0; mask < E; mask++) {
      string s1, s2;
      for (int j = 0; j < p.length(); j++) {
	if ((mask>>j)&1)
	  s1 += p[j];
	else
	  s2 += p[j];
      }
      ans += memo(make_pair(s1, k-1)) * memo(make_pair(s2, 1));
      ans %= MOD;
    }
  }
  seen.insert(key);
  return store[key] = ans;
}

int main(void) {
  int T; cin >> T;
  for (int c = 1; c <= T; c++) {
    string p; cin >> p; int K; cin >> K;
    int n; cin >> n;
    words.resize(n);
    seen = set < pair <string, int> > ();
    store = map < pair <string, int>, int> ();
    for (int i = 0; i < n; i++)
      cin >> words[i];
    vector <string> mono = parse(p, "+");
    vector <int> ans(K);
    for (int i = 0; i < mono.size(); i++)
      for (int k = 1; k <= K; k++)
	ans[k-1] += memo(make_pair(mono[i], k));
    printf("Case #%d: ", c);
    for (int k = 0; k < K; k++) {
      cout << ans[k] % MOD;
      if (k < K-1) cout << ' ';
    }
    cout << endl;
  }
}

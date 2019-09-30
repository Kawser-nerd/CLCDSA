#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <map>
using namespace std;

vector<pair<string, list<string> > > v;
map<string, int> w;
vector<int> b;

int solve(int i)
{
  if (b[i] != -1)
    return b[i];
  vector<int> a;
  for (typeof(v[i].second.begin()) j = v[i].second.begin();
       j != v[i].second.end(); ++j) {
    a.push_back(solve(w[*j]));
  }
  sort(a.begin(), a.end());
  int m = 1 + a.size();
  for (int j = 0; j < a.size(); ++j) {
    //cout << '+' << a[j] << endl;
    if (m < a[j] + a.size() - 1 - j)
      m = a[j] + a.size() - 1 - j;
  }
  b[i] = m;
  //cout << v[i].first << ' ' << m << endl;
  return m;
}

int main()
{
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; ++test) {
    int n;
    cin >> n;
    v.clear();
    w.clear();
    b.clear();
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      list<string> l;
      int m;
      cin >> m;
      while (m--) {
	string t;
	cin >> t;
	if (isupper(t[0]))
	  l.push_back(t);
      }
      v.push_back(make_pair(s, l));
      w.insert(make_pair(s, i));
      b.push_back(-1);
    }
    cout << "Case #" << test << ": "
	 << solve(0)
	 << endl;
  }
}

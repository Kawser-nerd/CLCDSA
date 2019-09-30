#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);

  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

string letters = "oi_eas_tbg";

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    int k; cin >> k;
    string s; cin >> s;

    set<string> ss;
    for (int i = 0; i+1 < s.size(); i++) {
      string tt = s.substr(i, 2); ss.insert(tt);

      int p1 = letters.find(tt[0]), p2 = letters.find(tt[1]);
      if (p1 != string::npos) {
        if (p2 != string::npos) {
          tt[1] = '0' + p2; ss.insert(tt);
          tt[1] = letters[p2];
        }
        tt[0] = '0' + p1; ss.insert(tt);
        if (p2 != string::npos) {
          tt[1] = '0' + p2; ss.insert(tt);
        }
      }
      else if (p2 != string::npos) {
        tt[1] = '0' + p2; ss.insert(tt);
      }
    }

    vector<string> sv;
    for (set<string>::iterator it = ss.begin(); it != ss.end(); ++it) {
      sv.push_back(*it);
      // cout << *it << endl;
    }
    int n = sv.size();

    VVI w(n, VI(n, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        w[i][j] = (sv[i][1] == sv[j][0]);
      }

    VI mr, mc;
    cout << "Case #" << c << ": " << 2*n - min(n-1, BipartiteMatching(w, mr, mc)) << endl;
  }
  return 0;
}

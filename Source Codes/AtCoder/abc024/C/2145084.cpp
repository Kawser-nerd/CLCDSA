#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int N, D, K;
  cin >> N >> D >> K;
  vector<int> l(D);
  vector<int> r(D);
  for (int i=0; i<D; i++){
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }

  vector<int> s(K);
  vector<int> t(K);
  for (int i=0; i<K; i++) {
    cin >> s[i] >> t[i];
    s[i]--;
    t[i]--;
  }

  vector<int> res(K, 0);

  int tmp;
  for (int i=0; i<D; i++) {
    for (int k=0; k<K; k++) {
      if (s[k] == t[k]) continue;
      res[k]++;
      if (l[i] <= s[k] && s[k] <= r[i]) {
        tmp = t[k] - s[k];
        if (tmp+s[k] < l[i]) s[k] = l[i];
        else if (tmp+s[k] > r[i]) s[k] = r[i];
        else s[k] += tmp;
      }
    }
  }

  for (int i=0; i<res.size(); i++) {
    cout << res[i] << endl;
  }
}
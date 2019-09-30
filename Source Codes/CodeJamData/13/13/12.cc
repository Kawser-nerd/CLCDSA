#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

double doit(int k, double p, int n) {
  double ret = 1.0;
  for (int i = 0; i < k; i++) ret *= p;
  for (int i = 0; i < n-k; i++) ret *= 1.0-p;
  for (int i = 1; i <= n; i++) ret *= i;
  for (int i = 1; i <= k; i++) ret /= i;
  for (int i = 1; i <= n-k; i++) ret /= i;
  return ret;
}

int kv[8000][12];
double kbestp[8000];
string kbests[8000];

main() {
  int T, R, N, M, K;
  cin >> T >> R >> N >> M >> K;
  for (int r = 0; r < R; r++)
  for (int k = 0; k < K; k++)
    cin >> kv[r][k];

  for (int n2 = 0; n2 <= N; n2++)
  for (int n3 = 0; n2+n3 <= N; n3++)
  for (int n4 = 0; n2+n3+n4 <= N; n4++)
  for (int n5 = 0; n2+n3+n4+n5 <= N; n5++)
  for (int n6 = 0; n2+n3+n4+n5+n6 <= N; n6++)
  for (int n7 = 0; n2+n3+n4+n5+n6+n7 <= N; n7++) {
    int n8 = N-n2-n3-n4-n5-n6-n7;
    if (n3 && M < 3) continue;
    if (n4 && M < 4) continue;
    if (n5 && M < 5) continue;
    if (n6 && M < 6) continue;
    if (n7 && M < 7) continue;
    if (n8 && M < 8) continue;
    double p = doit(n2, 1.0/(M-1), N);
    if (M >= 3) p *= doit(n3, 1.0/(M-2), N-n2);
    if (M >= 4) p *= doit(n4, 1.0/(M-3), N-n2-n3);
    if (M >= 5) p *= doit(n5, 1.0/(M-4), N-n2-n3-n4);
    if (M >= 6) p *= doit(n6, 1.0/(M-5), N-n2-n3-n4-n5);
    if (M >= 7) p *= doit(n7, 1.0/(M-6), N-n2-n3-n4-n5-n6);
    if (M >= 8) p *= doit(n8, 1.0/(M-7), N-n2-n3-n4-n5-n6-n7);
    string s;
    for (int i = 0; i < n2; i++) s += '2';
    for (int i = 0; i < n3; i++) s += '3';
    for (int i = 0; i < n4; i++) s += '4';
    for (int i = 0; i < n5; i++) s += '5';
    for (int i = 0; i < n6; i++) s += '6';
    for (int i = 0; i < n7; i++) s += '7';
    for (int i = 0; i < n8; i++) s += '8';

    vector<long long> val;
    vector<int> nval(100000);
    for (int b = 0; b < (1<<s.size()); b++) {
      long long v = 1;
      for (int i = 0; i < s.size(); i++) if (b&(1<<i)) v *= (int)(s[i]-'0');
      val.push_back(v);
      if (v < 100000) nval[v]++;
    }
    sort(val.begin(), val.end());
    for (int r = 0; r < R; r++) {
      double curp = p;
      for (int k = 0; k < K; k++) {
        if (kv[r][k] < 100000)
          curp *= nval[kv[r][k]];
        else
          curp *= upper_bound(val.begin(), val.end(), kv[r][k]) -
                  lower_bound(val.begin(), val.end(), kv[r][k]);
      }
      if (curp > kbestp[r]) {
        kbestp[r] = curp;
        kbests[r] = s;
      }
    }
  }
  cout << "Case #1:" << endl;
  for (int r = 0; r < R; r++)
    cout << kbests[r] << endl;
}

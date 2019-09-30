#include <bits/stdc++.h>

using namespace std;

const int N = 777777;

long long e[N], freq[N], old_freq[N];
long long mask[N], new_mask[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
      scanf("%lld", e + i);
    }
    for (int i = 0; i < cnt; i++) {
      scanf("%lld", freq + i);
      old_freq[i] = freq[i];
    }
    long long sum_neg = -e[0];
    for (int i = cnt - 1; i >= 0; i--) {
      e[i] -= e[0];
    }
    vector <long long> ret;
    while (true) {
      long long elem = -1;
      for (int i = 0; i < cnt; i++) {
        if (freq[i] > 0 && (i > 0 || freq[i] > 1)) {
          elem = e[i];
          break;
        }
      }
      if (elem == -1) {
        break;
      }
      ret.push_back(elem);
      int j = 0;
      for (int i = 0; i < cnt; i++) {
        while (j < cnt && e[j] + elem < e[i]) {
          j++;
        }
        if (0 <= j && j < cnt && e[j] + elem == e[i]) {
          if (i == j) {
            freq[i] /= 2;
          } else {
            freq[i] -= freq[j];
          }
        }
      }
    }
    int n = ret.size();
    for (int i = 0; i < cnt; i++) {
      mask[i] = -1;
    }
    mask[0] = 0;
    for (int q = 0; q < n; q++) {
      for (int i = 0; i < cnt; i++) {
        new_mask[i] = mask[i];
      }
      int j = 0;
      for (int i = 0; i < cnt; i++) {
        while (j < cnt && e[j] < e[i] + ret[q]) {
          j++;
        }
        if (mask[i] != -1) {
          if (0 <= j && j < cnt && e[j] == e[i] + ret[q]) {
            long long ft = mask[i] + (1LL << q);
            if (ft > new_mask[j]) {
              new_mask[j] = ft;
            }
          }
        }
      }
      for (int i = 0; i < cnt; i++) {
        mask[i] = new_mask[i];
      }
    }
    for (int i = 0; i < cnt; i++) {
      assert(mask[i] != -1);
    }
    for (int i = 0; i < cnt; i++) {
      if (e[i] == sum_neg) {
        for (int q = 0; q < n; q++) {
          if (mask[i] & (1LL << q)) {
            ret[q] = -ret[q];
          }
        }
      }
    }
    sort(ret.begin(), ret.end());
    vector < pair <long long, long long> > u;
    u.push_back(make_pair(0, 1));
    for (int q = 0; q < n; q++) {
      vector < pair <long long, long long> > nu;
      for (int i = 0; i < (int)u.size(); i++) {
        nu.push_back(u[i]);
        nu.push_back(make_pair(u[i].first + ret[q], u[i].second));
      }
      sort(nu.begin(), nu.end());
      int j = 1;
      for (int i = 1; i < (int)nu.size(); i++) {
        if (nu[i].first == nu[j - 1].first) {
          nu[j - 1].second += nu[i].second;
        } else {
          nu[j++] = nu[i];
        }
      }
      nu.resize(j);
      u = nu;
    }
    assert(u.size() == cnt);
    for (int i = 0; i < cnt; i++) {
      assert(u[i].first == e[i] - sum_neg);
      assert(u[i].second == old_freq[i]);
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) putchar(' ');
      printf("%lld", ret[i]);
    }
    printf("\n");
    fflush(stdout);
    cerr << "test " << qq << " ok, u.size() == " << u.size() << ", cnt = " << cnt << endl;
  }
  return 0;
}

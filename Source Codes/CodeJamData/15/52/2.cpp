#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int sum[N], from[N], to[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = k - 1; i < n; i++) {
      scanf("%d", sum + i);
    }
    int max_size = 0;
    int min_from = (int)1e9, max_to = -(int)1e9;
    for (int i = 0; i < k; i++) {
      from[i] = (i == 0 ? sum[k - 1] : 0);
      to[i] = from[i];
      int cur = from[i];
      for (int j = i + k; j < n; j += k) {
        cur += sum[j] - sum[j - 1];
        from[i] = min(from[i], cur);
        to[i] = max(to[i], cur);
      }
//      cout << from[i] << " " << to[i] << endl;
      min_from = min(min_from, from[i]);
      max_to = max(max_to, to[i]);
      max_size = max(max_size, to[i] - from[i]);
    }
    int sum_from = 0, sum_to = 0;
    for (int i = 0; i < k; i++) {
      sum_from += from[i];
      sum_to += to[i];
    }
    int low = max_size;
    int high = max_to - min_from;
    while (low < high) {
      int mid = (low + high) >> 1;
      bool ok = false;
      for (int lpos = min_from; lpos <= max_to - mid; lpos++) {
        int rpos = lpos + mid;
        int delta_min = 0, delta_max = 0;
/*        for (int i = 0; i < k; i++) {
          delta_min += lpos - from[i];
          delta_max += rpos - to[i];
        }*/
        delta_min += lpos * k - sum_from;
        delta_max += rpos * k - sum_to;
        if (delta_min <= 0 && 0 <= delta_max) {
//          cerr << mid << " -> good, lpos = " << lpos << ", rpos = " << rpos << ", delta_min_max = " << delta_min << " " << delta_max << endl;
          ok = true;
          break;
        }
      }
      if (ok) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    printf("%d\n", low);
  }
  return 0;
}

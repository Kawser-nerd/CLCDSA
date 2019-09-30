#include <cassert>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int next[2005];
int h[2005];
int bound[2005];

void solve (int l, int r) {
  if (l + 1 >= r) {
    return;
  }
  int i;
  for (i = l + 1; next[i] != r; i++) {
  }
//  cerr << l << " " << i << " " << r << endl;
  assert (i < r);
  h[i] = bound[i];

  for (int j = l + 1; j < r; j++) {
    bound[j] = min ((long long)bound[j], (long long)(j - i) * (h[r] - h[i]) / (r - i) + h[i] - 1);
  }

  solve (l, i);
  solve (i, r);
}

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn = 1; tn <= nt; tn++) {
    printf ("Case #%d:", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    int n;
    scanf("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
      scanf("%d", &next[i]);
      next[i]--;
    }

    int good = 1;
    for (int i = 0; i + 1 < n; i++)
      for (int j = i + 1; j + 1 < n && j < next[i]; j++) {
        if (next[j] > next[i]) {
          good = 0;
        }
      }
    if (!good) {
      puts (" Impossible");
      continue;
    }

    h[0] = (int)1e9;
    for (int i = 0; i + 1 < n; i = next[i]) {
      h[next[i]] = (int)1e9;

      for (int j = i + 1; j < next[i]; j++) {
        bound[j] = h[i] - 1;
      }

      solve (i, next[i]);
    }

    for (int i = 0; i < n; i++) {
      cout << " " << h[i];
    }
    cout << endl;
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int cs;
int num[2505];
int main() {
  scanf("%d", &t);
  for (int cs = 1; cs <= t; cs++) {
    scanf("%d", &n);
    memset(num, 0, sizeof(num));
    for (int i = 0; i < 2 * n - 1; i ++) {
      for (int j = 0; j < n; j++) {
        int tmp;
        scanf("%d", &tmp);
        num[tmp]++;
      }
    }
    vector<int> haha;
    for (int i = 0; i <= 2500; i++) {
      if (num[i] % 2 == 1) {
        haha.push_back(i);
      }
    }
    sort(haha.begin(), haha.end());
    printf("Case #%d:", cs);
    for (int i = 0; i < n; i++) {
      printf(" %d", haha[i]);
    }
    printf("\n");
  }

}

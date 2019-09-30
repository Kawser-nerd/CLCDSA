#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

unsigned long long tab[50][210];
char input[50];
int len;
int nums[50][50];

int main() {
  int N;
  scanf("%d", &N);

  for (int z = 1; z <= N; ++z) {
    scanf("%s", input);
    len = strlen(input);

    for (int start = 0; start <= len; ++start) {
      nums[start][start] = 0;

      for (int end = start + 1; end <= len; ++end) {
        nums[start][end] = (10 * nums[start][end - 1] + input[end-1] - '0') % 210;
      }
    }

    for (int i = 0; i <= len; ++i) {
      for (int j = 0; j < 210; ++j)
        tab[i][j] = 0;
    }

    tab[0][0] = 1;

    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < 210; ++j) {
        for (int k = i + 1; k <= len; ++k) {
          /* Count from i + 1 to k */
          int res = (j + nums[i][k]) % 210;

          tab[k][res] += tab[i][j];

          int res2 = (j + 210 - nums[i][k]) % 210;

          if (i != 0)
            tab[k][res2] += tab[i][j];
        }
      }
    }

    unsigned long long res = 0;

    for (int i = 0; i < 210; ++i) {
      if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
        res += tab[len][i];
    }

    cout << "Case #" << z << ": " << res << endl;
  }

  return 0;
}
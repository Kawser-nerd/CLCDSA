#include <algorithm>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <bitset>
#include <ext/hash_set>
#include <ext/hash_map>
#include <stdexcept>
using namespace std;
using namespace __gnu_cxx;

const char msg[] = "welcome to code jam";
const int len = 19;

const int mod = 10000;
int f[512][len + 1]; // f[i][j] = ways to get msg[j..] from s[i..]

int main() {
  int cases;
  scanf("%i\n", &cases);
  for (int caseno = 1; caseno <= cases; ++caseno) {
    printf("Case #%i: ", caseno);
    string s;

    getline(cin, s);
    int n = s.size();

    fill(&f[n][0], &f[n][len], 0);
    f[n][len] = 1;
    for (int i = n - 1; i >= 0; --i) {
      f[i][len] = 1;
      for (int j = len - 1; j >= 0; --j) {
        f[i][j] = f[i + 1][j];
        if (s[i] == msg[j])
          f[i][j] = (f[i][j] + f[i + 1][j + 1]) % mod;
      }
    }
      
    printf("%04d\n", f[0][0]);
    fflush(stdout);
  }
  return 0;
}

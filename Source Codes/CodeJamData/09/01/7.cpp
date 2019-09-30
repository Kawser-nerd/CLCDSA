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

typedef long long ll;
const int infinity = 1000000000;

int main() {
  int len, numwords, cases;
  scanf("%i%i%i", &len, &numwords, &cases);

  vector<string> word;
  string s;
  for (int i = 0; i < numwords; ++i) {
    cin >> s;
    word.push_back(s);
  }

  for (int caseno = 1; caseno <= cases; ++caseno) {
    printf("Case #%i: ", caseno);

    char valid[len][256];
    fill(&valid[0][0], &valid[len][0], false);
    cin >> s;

    int l = 0;
    for (int i = 0; i < s.size(); ++i, ++l)
      if (s[i] == '(') {
        ++i;
        while (s[i] != ')')
          valid[l][s[i++]] = true;
      } else valid[l][s[i]] = true;

    int ret = 0;
    for (int i = 0; i < numwords; ++i) {
      int j;
      for (j = 0; j < len; ++j)
        if (!valid[j][word[i][j]]) break;
      if (j == len) ++ret;
    }
    printf("%i\n", ret);
    fflush(stdout);
  }
  return 0;
}

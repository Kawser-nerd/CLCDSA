#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

vector<string> digits = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main(void) {
  vector<pair<int, char>> v;
  vector<bool> bio(10, false);
  while (v.size() < 10) {
    REP(j, 10)
      if (!bio[j]) {
        char ch = -1;
        for (char c: digits[j]) {
          bool ok = true;
          REP(k, 10)
            if (k != j && !bio[k]) {
              ok &= find(digits[k].begin(), digits[k].end(), c) == digits[k].end();
            }
          if (ok) { ch = c; break; }
        }
        if (ch != -1) {
          v.push_back({j, ch});
          bio[j] = true;
        }
      }
  }

  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    char s[2222];
    scanf("%s", s);
    static int cnt[26];
    REP(j, 26) cnt[j] = 0;
    int len = strlen(s);
    REP(j, len) cnt[s[j]-'A']++;

    static int ans[10];
    REP(j, 10) ans[j] = 0;
    
    for (auto& p: v) {
      int x = cnt[p.second - 'A'];
      ans[p.first] = x;
      for (char c: digits[p.first]) {
        assert(cnt[c-'A'] >= x);
        cnt[c-'A'] -= x;
      }
    }

    REP(j, 26) assert(cnt[j] == 0);
    
    printf("Case #%d: ", tp);
    REP(j, 10) REP(k, ans[j]) putchar('0' + j);
    putchar('\n');
  }
  return 0;
}

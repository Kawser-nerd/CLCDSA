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

const string NO = "IMPOSSIBLE";

string solve(int R, int S, int P) {
  if (R < 0 || S < 0 || P < 0) return NO;
  if (R + S + P == 1) {
    if (R > 0) return "R";
    if (S > 0) return "S";
    return "P";
  }

  int p = (P + R - S) / 2;
  int r = (R + S - P) / 2;
  int s = (S + P - R) / 2;
  
  string ans = solve(r, s, p);
  if (ans == NO) return NO;

  string nAns = "";
  for (char c: ans) {
    if (c == 'R') nAns += "RS";
    else if (c == 'P') nAns += "PR";
    else nAns += "SP";
  }
  return nAns;
}

string sort(string s) {
  if (s.size() == 1) return s;
  string a = sort(s.substr(0, s.size() / 2));
  string b = sort(s.substr(s.size() / 2, s.size() / 2));
  if (a < b) return a + b;
  return b + a;
}

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    int N, R, S, P;
    scanf("%d %d %d %d", &N, &R, &P, &S);
    string ans = solve(R, S, P);
    if (ans != NO) ans = sort(ans);
    
    printf("Case #%d: ", tp);
    printf("%s\n", ans.c_str());
  }
  return 0;
}

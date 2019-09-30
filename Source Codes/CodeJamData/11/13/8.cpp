#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    solve();
  }
}

int n, m;
int c[100];
int s[100];
int t[100];

int ss[100];
int greedy(const set<int> &hand, int turn) {
  int k = 0;
  int ret = 0;
  FORIT(it, hand) {
    ss[k++] = s[*it];
  }
  sort(ss, ss + k);
  reverse(ss, ss + k);
  REP(i, min(k, turn)) { ret += ss[i]; }
  return ret;
}

int calc(set<int> hand, int depth, int turn);
int useCard(int index, set<int> hand, int depth, int turn) {
  int score = s[index];
  int ndepth = min(depth + c[index], n + m);
  int nturn = turn + t[index] - 1;
  FOR(i, depth, ndepth) { hand.insert(i); }
  hand.erase(index);
  return calc(hand, ndepth, nturn) + score;
}

int calc(set<int> hand, int depth, int turn) {
  if (hand.empty() || turn == 0) { return 0; }
  int ret = 0;
  FORIT(it, hand) {
    if (t[*it] != 0) {
      return useCard(*it, hand, depth, turn);
    }
  }
  ret = greedy(hand, turn);
  int maxs1 = 0;
  int index1 = -1;
  int maxs2 = 0;
  int index2 = -1;
  FORIT(it, hand) {
    if (c[*it] >= 1) {
      if (c[*it] == 1) {
        if (s[*it] > maxs1) {
          maxs1 = s[*it];
          index1 = *it;
        }
      } else {
        if (s[*it] > maxs2) {
          maxs2 = s[*it];
          index2 = *it;
        }
      }
    }
  }
  if (index1 != -1) {
    ret = max(ret, useCard(index1, hand, depth, turn));
  }
  if (index2 != -1) {
    ret = max(ret, useCard(index2, hand, depth, turn));
  }
  return ret;
}

void solve() {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d %d %d", &c[i], &s[i], &t[i]);
  }
  scanf("%d", &m);
  FOR(i, n, n + m) {
    scanf("%d %d %d", &c[i], &s[i], &t[i]);
  }
  set<int> hand;
  REP(i, n) { hand.insert(i); }
  printf("%d\n", calc(hand, n, 1));
}

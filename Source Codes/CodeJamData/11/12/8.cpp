#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <string>
#include <map>

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
    printf("Case #%d:", test_case);
    solve();
  }
}

int n, m;
char order[1000];
string dict[100010];
int exist[100010];

pair<int, int> calc(vector<int> &cand, int rest, int cost) {
  assert(!cand.empty());
  if (cand.size() == 1) {
    return make_pair(cost, -cand[0]);
  }
  int usable = 0;
  FORIT(it, cand) {
    usable |= exist[*it];
    //cout << *it << " ";
  }
  //puts("");
  rest &= usable;
  char target = 0;
  REP(i, 26) {
    int c = order[i] - 'a';
    if (rest & (1 << c)) { target = c; break; }
  }
  rest ^= 1 << (int)target;
  target += 'a';

  map<string, vector<int> > mapto;
  map<string, int> ncost;
  FORIT(it1, cand) {
    string nstring = dict[*it1];
    int nc = cost + 1;
    FORIT(it2, nstring) {
      if (*it2 == target) { nc = cost; }
      if (rest & (1 << (*it2 - 'a'))) {
        *it2 = '_';
      }
    }
    if (!mapto.count(nstring)) {
      mapto[nstring] = vector<int>();
      ncost[nstring] = nc;
    }
    mapto[nstring].push_back(*it1);
  }

  pair<int, int> ret = make_pair(-1, -1);
  FORIT(it, mapto) {
    ret = max(ret, calc(it->second, rest, ncost[it->first]));
  }
  return ret;
}

void solve() {
  //puts("");
  scanf("%d %d", &n, &m);
  MEMSET(exist, 0);
  vector<int> cand[12];
  REP(i, n) {
    cin >> dict[i];
    cand[dict[i].size()].push_back(i);
    FORIT(it, dict[i]) {
      exist[i] |= 1 << (*it - 'a');
    }
  }
  REP(i, m) {
    scanf("%s", order);
    pair<int, int> ans = make_pair(-1, -1);
    FOREQ(j, 0, 10) {
      if (cand[j].empty()) { continue; }
      ans = max(ans, calc(cand[j], (1 << 26) - 1, 0));
    }
    cout << " " << dict[-ans.second];
  }
  puts("");
}

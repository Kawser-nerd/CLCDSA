#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int inf = (int)1e9;

const int MAX_ID = 2002;
const int N = 4010;

char c[N];
int id[N];

int last[N];

vector < pair < pair <int, int>, int > > need_e, need_l;
bool solved_e[N], solved_l[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      c[i] = getchar();
      while (c[i] != 'E' && c[i] != 'L') {
        c[i] = getchar();
      }
      scanf("%d", id + i);
    }
    need_e.clear();
    need_l.clear();
    for (int cur = 1; cur <= MAX_ID; cur++) {
      char prev = 'N';
      int pos = -1;
      for (int i = 0; i < n; i++) {
        if (id[i] == cur) {
          if (prev == c[i]) {
            if (c[i] == 'L') {
              need_e.push_back(make_pair(make_pair(pos, i), cur));
            } else {
              need_l.push_back(make_pair(make_pair(pos, i), cur));
            }
          }
          prev = c[i];
          pos = i;
        }
      }
    }
    int cnt_e = need_e.size();
    int cnt_l = need_l.size();
    for (int i = 0; i < cnt_e; i++) {
      solved_e[i] = false;
    }
    for (int i = 0; i < cnt_l; i++) {
      solved_l[i] = false;
    }
    for (int i = 0; i < n; i++) {
      if (c[i] == 'L' && id[i] == 0) {
        int mn = inf, km = -1;
        for (int j = 0; j < cnt_l; j++) {
          if (!solved_l[j]) {
            pair <int, int> p = need_l[j].first;
            if (p.first <= i && i <= p.second) {
              if (p.second < mn) {
                mn = p.second;
                km = j;
              }
            }
          }
        }
        if (mn == inf) {
          continue;
        }
        solved_l[km] = true;
        id[i] = need_l[km].second;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (c[i] == 'E' && id[i] == 0) {
        int mx = -inf, km = -1;
        for (int j = 0; j < cnt_e; j++) {
          if (!solved_e[j]) {
            pair <int, int> p = need_e[j].first;
            if (p.first <= i && i <= p.second) {
              if (p.first > mx) {
                mx = p.first;
                km = j;
              }
            }
          }
        }
        if (mx == -inf) {
          continue;
        }
        solved_e[km] = true;
        id[i] = need_e[km].second;
      }
    }
    bool ok = true;
    for (int i = 0; i < cnt_e; i++) {
      if (!solved_e[i]) {
        ok = false;
        break;
      }
    }
    for (int i = 0; i < cnt_l; i++) {
      if (!solved_l[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      printf("CRIME TIME\n");
      fflush(stdout);
      continue;
    }
    int ans = 0;
    vector <int> ls;
    for (int i = n - 1; i >= 0; i--) {
      if (c[i] == 'L') {
        ls.push_back(id[i]);
      } else {
        int lcnt = ls.size();
        if (lcnt == 0) {
          ans++;
          continue;
        }
        bool ok = false;
        for (int j = 0; j < lcnt; j++) {
          if (id[i] != 0 && ls[j] == id[i]) {
            ls[j] = ls[lcnt - 1];
            ls.pop_back();
            ok = true;
            break;
          }
        }
        if (!ok) {
          if (id[i] != 0) {
            bool ok = false;
            for (int j = 0; j < lcnt; j++) {
              if (ls[j] == 0) {
                ls[j] = ls[lcnt - 1];
                ls.pop_back();
                ok = true;
                break;
              }
            }
            if (!ok) {
              ans++;
            }
            continue;
          }
          for (int cur = 1; cur <= MAX_ID; cur++) {
            last[cur] = -1;
          }
          for (int ni = i - 1; ni >= 0; ni--) {
            if (c[ni] == 'E' && id[ni] != 0) {
              if (last[id[ni]] == -1) {
                last[id[ni]] = ni;
              }
            }
          }
          int mn = inf, km = -1;
          for (int j = 0; j < lcnt; j++) {
            if (ls[j] == 0) {
              continue;
            }
            int u = last[ls[j]];
            if (u < mn) {
              mn = u;
              km = j;
            }
          }
          if (mn == -1) {
            ls[km] = ls[lcnt - 1];
            ls.pop_back();
            continue;
          }
          int pos = -1;
          for (int ni = mn; ni < i; ni++) {
            if (c[ni] == 'L' && id[ni] == 0) {
              pos = ni;
              break;
            }
          }
          if (pos != -1) {
            id[pos] = ls[km];
            ls[km] = ls[lcnt - 1];
            ls.pop_back();
            continue;
          }
          ok = false;
          for (int j = 0; j < lcnt; j++) {
            if (ls[j] == 0) {
              ls[j] = ls[lcnt - 1];
              ls.pop_back();
              ok = true;
              break;
            }
          }
          if (!ok) {
            ans++;
          }
        }
      }
    }
    printf("%d\n", ans);
    fflush(stdout);
  }
  return 0;
}

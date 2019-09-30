#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>
#include <string>

using namespace std;
typedef int64_t i64;

string place(i64 nr, i64 ny, i64 nb) {
    string ans(nr + ny + nb, ' ');
    vector<pair<i64, char>> v = {{nr, 'R'}, {ny, 'Y'}, {nb, 'B'}};
    sort(v.begin(), v.end());

    int at = 0;
    for (i64 i = 0; i < v[2].first; i++) {
      ans[at] = v[2].second;
      at += 2;
    }
    at--;
    for (i64 i = 0; i < v[1].first; i++) {
      if (at < ans.size()) {
        ans[at] = v[1].second;
        at += 2;
      } else {
        at = 1;
        ans[at] = v[1].second;
        at += 2;
      }
    }
    i64 t = 0;
    for (i64 i = 0; i < ans.size(); i++) {
      if (ans[i] == ' ') {
        ans[i] = v[0].second;
        t++;
      }
    }
    assert(t == v[0].first);
    for (i64 i = 0; i < ans.size(); i++) {
      assert(ans[i] != ans[(i+1)%ans.size()]);
      assert(ans[i] != ' ');
    }
    return ans;
}

string replace(string ans, char o, char n, i64 times) {
  if(times == 0)
    return ans;
  for (i64 i = 0; i < ans.size(); i++) {
    if (ans[i] == o) {
      string output = ans.substr(0, i + 1);
      for (i64 j = 0; j < times; j++) {
        output += n;
        output += o;
      }
      output += ans.substr(i+1);
      return output;
    }
  }
  assert(false);
}

void check(string ans, i64 R, i64 O, i64 Y, i64 G, i64 B, i64 V) {
  assert(ans.size() == R + O + Y + G + B + V);
  i64 r = 0, o = 0, y = 0, g = 0, b = 0, v = 0;
  for (i64 i = 0; i < ans.size(); i++) {
    i64 p = (i - 1 + ans.size()) % ans.size();
    i64 n = (i + 1 + ans.size()) % ans.size();
    if (ans[i] == 'G') {
      g++;
      assert(ans[p] == 'R');
      assert(ans[n] == 'R');
    } else if (ans[i] == 'V') {
      v++;
      assert(ans[p] == 'Y');
      assert(ans[n] == 'Y');
    } else if (ans[i] == 'O') {
      o++;
      assert(ans[p] == 'B');
      assert(ans[n] == 'B');
    } else {
      assert(ans[p] != ans[i] && ans[n] != ans[i]);
    }
    if (ans[i] == 'R')
      r++;
    if (ans[i] == 'Y')
      y++;
    if (ans[i] == 'B')
      b++;
  }
  assert(R == r && O == o && Y == y && G == g && B == b && V == v);
}

int main() {
  i64 T;
  scanf("%lld", &T);
  for (i64 zz = 1; zz <= T; zz++) {
    i64 N, R, O, Y, G, B, V;
    scanf("%lld %lld %lld %lld %lld %lld %lld", &N, &R, &O, &Y, &G, &B, &V);

    i64 nr = R - G;
    i64 ny = Y - V;
    i64 nb = B - O;

    if (nr < 0 || ny < 0 || nb < 0 || max(nr, max(ny, nb)) * 2 > (nr + ny + nb)) {
      printf("Case #%lld: IMPOSSIBLE\n", zz);
      continue;
    }
    if (nr == 0 && ny == 0 && nb == 0) {
      i64 greater = (G > 0 ? 1 : 0) + (V > 0 ? 1 : 0) + (O > 0 ? 1 : 0);
      assert(greater > 0);
      if (greater > 1) {
        printf("Case #%lld: IMPOSSIBLE\n", zz);
        continue;
      }
      string ans;
      char a, b;
      if (G > 0) {
        a = 'R';
        b = 'G';
      } else if (V > 0) {
        a = 'Y';
        b = 'V';
      } else if (O > 0) {
        a = 'B';
        b = 'O';
      }
      for (i64 i = 0; i < max(G, max(V, O)); i++) {
        ans += a;
        ans += b;
      }
      check(ans, R, O, Y, G, B, V);
      printf("Case #%lld: %s\n", zz, ans.c_str());
      continue;
    }
    if ((nr == 0 && G > 0) || (ny == 0 && V > 0) || (nb == 0 && O > 0)) {
      printf("Case #%lld: IMPOSSIBLE\n", zz);
      continue;
    }
    auto ans1 = place(nr, ny, nb);
    auto a2 = replace(ans1, 'R', 'G', G);
    auto a3 = replace(a2, 'Y', 'V', V);
    auto ans2 = replace(a3, 'B', 'O', O);
    check(ans2, R, O, Y, G, B, V);
    printf("Case #%lld: %s\n", zz, ans2.c_str());
  }
}

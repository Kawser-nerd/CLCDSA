#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long) 2e18;

int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    long long hd, ad, hk, ak, b, d;
    cin >> hd >> ad >> hk >> ak >> b >> d;
    long long to_kill;
    if (b == 0) {
      to_kill = (hk - 1) / ad + 1;
    } else {
      to_kill = inf;
      for (long long buffs = 0; buffs < to_kill; buffs++) {
        long long new_attack = ad + buffs * b;
        long long cur_turns = buffs + ((hk - 1) / new_attack + 1);
        to_kill = min(to_kill, cur_turns);
      }
    }
    long long ans = inf;
    long long health = hd;
    bool healed_last = false;
    for (long long it = 0; it < ans; it++) {
      long long turns;
      if (ak == 0) {
        turns = it + to_kill;
      } else {
        long long till_next_cure = (health - 1) / ak;
        if (to_kill <= till_next_cure + 1) {
          turns = it + to_kill;
        } else {
          turns = it + till_next_cure + 1;
          long long need_more = to_kill - till_next_cure;
          long long between_cures = (hd - 1) / ak - 1;
          if (between_cures <= 0) {
            turns = inf;
          } else {
            long long periods = (need_more - 2) / between_cures;
            turns += periods * (between_cures + 1);
            need_more -= periods * between_cures;
            assert(need_more <= between_cures + 1);
            turns += need_more;
          }
        }
      }
      ans = min(ans, turns);
      if (d == 0) {
        break;
      }
      bool healed_now = false;
      long long ak_if_debuff = max(0LL, ak - d);
      if (health > ak_if_debuff) {
        ak = ak_if_debuff;
      } else {
        health = hd;
        healed_now = true;
      }
      health -= ak;
      if (health <= 0) {
        break;
      }
      if (healed_last && healed_now) {
        break;
      }
      healed_last = healed_now;
    }
    if (ans == inf) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}

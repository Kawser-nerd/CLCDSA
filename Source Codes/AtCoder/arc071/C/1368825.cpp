#include<iostream>
#include <vector>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  std::vector<unsigned> s_cnt(s.size() + 1);
  std::vector<unsigned> t_cnt(t.size() + 1);
  s_cnt[0] = 0;
  for (unsigned i = 1; i <= s.size(); ++i) {
    s_cnt[i] = s_cnt[i - 1] + (s[i - 1] == 'A' ? 1 : 2);
  }
  t_cnt[0] = 0;
  for (unsigned i = 1; i <= t.size(); ++i) {
    t_cnt[i] = t_cnt[i - 1] + (t[i - 1] == 'A' ? 1 : 2);
  }
  unsigned q;
  std::cin >> q;
  for (unsigned i = 0; i < q; ++i) {
    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << (((s_cnt[b] - s_cnt[a-1]) % 3 == (t_cnt[d] - t_cnt[c-1]) % 3) ? "YES" : "NO") << std::endl;
  }
  return 0;
}
#include <iostream>
#include <vector>

std::vector<int> KMP(const std::string &s) {
  std::vector<int> ret(s.size() + 1);
  ret[0] = -1;
  int j = -1;
  for (unsigned i = 0; i < s.size(); ++i) {
    while (j >= 0 && s[i] != s[j]) { j = ret[j]; }
    ++j;
    ret[i + 1] = j;
  }
  ret[0] = 0;
  return ret;
}

std::vector<unsigned> period(const std::string &s) {
  auto x = KMP(s);
  std::vector<unsigned> ret(s.size());
  for (unsigned i = 0; i < s.size(); ++i) {
    ret[i] = i + 1 - x[i + 1];
  }
  return ret;
}

int main() {
  std::string s;
  std::cin >> s;
  auto lens = s.size();
  while (s.size() > lens / 2) { s.pop_back(); }
  unsigned long long l, r;
  std::cin >> l >> r;
  auto per = period(s).back();
  if (s.size() % per == 0) {
    std::vector<unsigned long long> cnt('z' - 'a' + 1, 0);
    unsigned long long lq = (l - 1) / per;
    unsigned long long lr = (l - 1) % per;
    unsigned long long rq = r / per;
    unsigned long long rr = r % per;
    for (unsigned i = 0; i < per; ++i) { cnt[s[i] - 'a'] += rq - lq; }
    for (unsigned i = 0; i < rr; ++i) { ++cnt[s[i] - 'a']; }
    for (unsigned i = 0; i < lr; ++i) { --cnt[s[i] - 'a']; }
    for (unsigned i = 0; i < cnt.size(); ++i) {
      std::cout << cnt[i] << " ";
    }
    std::cout << std::endl;
  } else {
    std::vector<unsigned long long> len;
    len.push_back(s.size());
    len.push_back(s.size() + per);
    while (len.back() < r) {
      auto x = len[len.size() - 1];
      auto y = len[len.size() - 2];
      len.push_back(x + y);
    }
    std::vector<unsigned long long> cnt_s('z' - 'a' + 1, 0);
    for (auto &c : s) { ++cnt_s[c - 'a']; }
    std::vector<unsigned long long> cnt_gs('z' - 'a' + 1, 0);
    for (unsigned i = 0; i < cnt_s.size(); ++i) { cnt_gs[i] = cnt_s[i]; }
    for (unsigned i = 0; i < per; ++i) { ++cnt_gs[s[i] - 'a']; }
    for (int i = 0; i <= 'z' - 'a'; ++i) {
      std::vector<unsigned long long> cnt;
      cnt.push_back(cnt_s[i]);
      cnt.push_back(cnt_gs[i]);
      for (unsigned j = 2; j < len.size(); ++j) {
        auto x = cnt[cnt.size() - 1];
        auto y = cnt[cnt.size() - 2];
        cnt.push_back(x + y);
      }
      unsigned long long ans = 0;
      auto rr = r;
      for (auto j = len.size() - 1; j > 1; --j) {
        if (len[j] > rr) { continue; }
        rr -= len[j];
        ans += cnt[j];
      }
      if (rr >= len[1]) {
        rr -= len[1];
        ans += cnt[1];
        for (unsigned j = 0; j < rr; ++j) {
          if (s[j] - 'a' == i) { ++ans; }
        }
      } else {
        for (unsigned j = 0; j < s.size() && rr; ++j) {
          --rr;
          if (s[j] - 'a' == i) { ++ans; }
        }
        for (unsigned j = 0; j < rr; ++j) {
          if (s[j] - 'a' == i) { ++ans; }
        }
      }
      auto ll = l - 1;
      for (auto j = len.size() - 1; j > 1; --j) {
        if (len[j] > ll) { continue; }
        ll -= len[j];
        ans -= cnt[j];
      }
      if (ll >= len[1]) {
        ll -= len[1];
        ans -= cnt[1];
        for (unsigned j = 0; j < ll; ++j) {
          if (s[j] - 'a' == i) { --ans; }
        }
      } else {
        for (unsigned j = 0; j < s.size() && ll; ++j) {
          --ll;
          if (s[j] - 'a' == i) { --ans; }
        }
        for (unsigned j = 0; j < ll; ++j) {
          if (s[j] - 'a' == i) { --ans; }
        }
      }
      std::cout << ans << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
#include <cstdio>
#include <string>
#include <vector>

std::string sim(const std::string& t0, const std::string& s) {
  size_t n = s.length();
  std::string res = t0;
  for (size_t i = 1; i <= n; ++i) {
    size_t pi = i-1;
    size_t ci = (i<n? i:0);

    char cur;
    if (res[ci] == 'S') {
      if (s[ci] == 'o') {
        cur = res[pi];
      } else {
        cur = res[pi] ^ 'S' ^ 'W';
      }
    } else {
      if (s[ci] == 'o') {
        cur = res[pi] ^ 'S' ^ 'W';
      } else {
        cur = res[pi];
      }
    }
    res += cur;
  }

  if (res[1] != res[n+1]) return {};
  if (res[0] != res[n]) return {};
  res.pop_back();
  res.pop_back();
  return res;
}

int main() {
  size_t N;
  scanf("%zu", &N);

  char buf[131072];
  scanf("%s", buf);
  std::string s = buf;

  std::vector<std::string> t0 = {"SS", "SW", "WS", "WW"};
  for (auto t: t0) {
    std::string res = sim(t, s);
    if (!res.empty())
      return !printf("%s\n", res.c_str());
  }

  puts("-1");
}
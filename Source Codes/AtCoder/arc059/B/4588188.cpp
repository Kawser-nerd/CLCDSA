#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <string>

int main() {
  char buf[131072];
  scanf("%s", buf);
  std::string s = buf;

  for (size_t i = 1; i < s.length(); ++i)
    if (s[i-1] == s[i])
      return !printf("%zu %zu\n", i, i+1);

  for (size_t i = 1; i+1 < s.length(); ++i)
    if (s[i-1] == s[i+1])
      return !printf("%zu %zu\n", i, i+2);

  puts("-1 -1");
}
#include <cstdio>
#include <string>

int main() {
  char buf[131072];
  scanf("%s", buf);
  std::string s = buf;

  puts(((s.front() == s.back()) ^ (s.length() % 2 == 1))? "First":"Second");
}
#include <iostream>
#include <string>
int main(void) {
  std::string s, t;
  std::cin >> s >> t;
  bool f = false;
  for (auto i = s.begin(); i != s.end(); i++) {
    char x = s.back();
    s.pop_back();
    s.insert(s.begin(), x);
    if (s == t) {
      f = true;
      break;
    }
  }
  if (f)
    std::cout << "Yes";
  else
    std::cout << "No";
  std::cout << std::endl;
  return 0;
}
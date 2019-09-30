#undef HOGE
#include <iostream>

bool ask(uint64_t n) {
  std::cout << "? " << n << std::endl;
#ifdef HOGE
  std::string sq = std::to_string(n);
  std::string sa = std::to_string(N);
  return sq <= sa == n <= N;
#else
  std::string s;
  std::cin >> s;
  return s == "Y";
#endif
}

int main() {
  unsigned long long ans = 0;
  unsigned long long d = 10;
  std::string s;
  while (true) {
    if (ask((ans * 10 + 6) * 1000000000 - 1)) {
      if (ask((ans * 10 + 4) * 1000000000 - 1)) {
        if (ask((ans * 10 + 2) * 1000000000 - 1)) {
          if (ans == 0) {
            ans = 1;
            if (ask(2)) { break; }
          } else {
            if (ask((ans * 10 + 1) * 1000000000 - 1)) {
              ans *= 10;
              if (ans == d / 10 && ask(d - 1)) { break; }
            } else {
              ans *= 10;
              ans += 1;
            }
          }
        } else {
          if (ask((ans * 10 + 3) * 1000000000 - 1)) {
            ans *= 10;
            ans += 2;
          } else {
            ans *= 10;
            ans += 3;
          }
        }
      } else {
        if (ask((ans * 10 + 5) * 1000000000 - 1)) {
          ans *= 10;
          ans += 4;
        } else {
          ans *= 10;
          ans += 5;
        }
      }
    } else {
      if (ask((ans * 10 + 8) * 1000000000 - 1)) {
        if (ask((ans * 10 + 7) * 1000000000 - 1)) {
          ans *= 10;
          ans += 6;
        } else {
          ans *= 10;
          ans += 7;
        }
      } else {
        if (ask((ans * 10 + 9) * 1000000000 - 1)) {
          ans *= 10;
          ans += 8;
        } else {
          ans *= 10;
          ans += 9;
        }
      }
    }
    if (!ask(d)) { break; }
    d *= 10;
    if (ans * 10 >= 1000000000) { break; }
  }
  if (ans == 100000000) {
    if (!ask(999999999)) { ans *= 10; }
  }
  std::cout << "! " << ans << std::endl;
  std::cout << std::flush;
  return 0;
}
#include <iostream>
#include <string>

std::string try_restore(const std::string& S, const std::string& T, size_t k) {
  std::string res = S;
  for (size_t i = 0; i < T.length(); ++i) {
    if (S[i+k] == '?') {
      res[i+k] = T[i];
    } else if (S[i+k] != T[i]) {
      return "~";
    }
  }
  for (auto& c: res)
    if (c == '?') c = 'a';
  return res;
}

int main() {
  std::string S, T;
  std::cin >> S >> T;

  if (T.length() > S.length())
    return (std::cout << "UNRESTORABLE" << std::endl), 0;

  std::string Z = "~";
  for (size_t i = 0; i+T.length() <= S.length(); ++i)
    Z = std::min(Z, try_restore(S, T, i));

  if (Z == "~") Z = "UNRESTORABLE";
  std::cout << Z << std::endl;
}
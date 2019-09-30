#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  std::cin >> N;

  std::vector<int> freq(26);
  for (size_t i = 0; i < N; ++i) {
    std::string S;
    std::cin >> S;
    ++freq[S[0]-'A'];
  }

  using namespace std::string_literals;
  std::vector<intmax_t> march;
  for (int i: "MARCH"s)
    march.push_back(freq[i-'A']);

  intmax_t res = 0;
  res += march[0] * march[1] * march[2];
  res += march[0] * march[1] * march[3];
  res += march[0] * march[1] * march[4];
  res += march[0] * march[2] * march[3];
  res += march[0] * march[2] * march[4];
  res += march[0] * march[3] * march[4];
  res += march[1] * march[2] * march[3];
  res += march[1] * march[2] * march[4];
  res += march[1] * march[3] * march[4];
  res += march[2] * march[3] * march[4];

  std::cout << res << std::endl;
}
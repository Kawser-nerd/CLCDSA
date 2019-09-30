#include <iostream>
#include <unordered_map>

const unsigned long long mod = 1000000007;
std::unordered_map<unsigned long long, unsigned long long> map;

unsigned long long solve(unsigned long long max) {
  auto p = map.find(max);
  if (p != map.end()) { return p->second; }
  if (max == 0) { return 1; }
  if (max == 1) { return 2; }
  auto ret = solve(max / 2) + solve((max - 1) / 2) + solve((max - 2) / 2);
  ret %= mod;
  map.insert(std::make_pair(max, ret));
  return ret;
}

int main() {
  unsigned long long N;
  std::cin >> N;
  std::cout << solve(N) << std::endl;
  return 0;
}
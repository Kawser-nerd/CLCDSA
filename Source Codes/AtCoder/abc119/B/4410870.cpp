#include <iostream>
#include <sstream>
#include <string>
#include <vector>

constexpr double BTC_YEN = 380000.0l;

int main(int argc, char* args[]) {
  using std::string;
  int line;
  int jpy = 0;
  double btc = 0.0l;
  
  std::cin >> line;
  for (int i = 0; i < line; ++i) {
    string cur;
    double amount;
    std::cin >> amount;
    std::cin >> cur;
    if (cur == "JPY") {
      jpy += amount;
    } else {
      btc += amount;
    }
  }
  double total = static_cast<double>(jpy);
  total += btc * BTC_YEN;
  
  std::cout << total;
  
  return 0;
}
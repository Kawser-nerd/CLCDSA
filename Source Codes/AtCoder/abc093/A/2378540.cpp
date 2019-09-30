#include <iostream>
#include<array>
#include<string>

using namespace std;
int main(int argc, char const *argv[]) {
  char a[2];
  std::cin >> a;
  for (size_t i = 1; i < 3; i++) {
    if (a[0]==a[i] || a[i-1]==a[i]) {
      std::cout << "No" << '\n';
      return 0;
    }
  }
  std::cout << "Yes" << '\n';
  return 0;
}
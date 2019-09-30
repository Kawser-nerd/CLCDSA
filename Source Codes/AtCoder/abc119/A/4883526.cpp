#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char const *argv[]) {
  string S;
  std::cin >> S;
  (stoi(S.substr(5, 2)) > 4)?std::cout << "TBD" << '\n':std::cout << "Heisei" << '\n';
  return 0;
}
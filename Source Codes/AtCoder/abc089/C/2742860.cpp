#include <iostream>
#include <vector>
#include <string>

const std::vector<char> chars = { 'M', 'A', 'R', 'C', 'H' };

int main() {
  int N;
  std::cin >> N;

  std::vector<long long int> s(26, 0);

  for (int i = 0; i < N; i++) {
    std::string S;
    std::cin >> S;

    s[S[0]]++;
  }

  long long int answer = 0;

  for (int i = 0; i < chars.size(); i++) {
    for (int j = i+1; j < chars.size(); j++) {
      for (int k = j+1; k < chars.size(); k++) {
        answer += s[chars[i]] * s[chars[j]] * s[chars[k]];
      }
    }
  }

  std::cout << answer << std::endl;
}
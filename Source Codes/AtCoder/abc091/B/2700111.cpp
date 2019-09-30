#include <iostream>
#include <map>
#include <string>

int main() {
  int N, M;
  std::cin >> N;

  std::map<std::string, int> m;

  for (int i = 0; i < N; i++) {
    std::string s;
    std::cin >> s;

    m[s]++;
  }

  std::cin >> M;

  for (int i = 0; i < M; i++) {
    std::string s;
    std::cin >> s;

    m[s]--;
  }

  int answer = 0;

  for (auto p : m) {
    answer = std::max(answer, p.second);
  }

  std::cout << answer << std::endl;
}
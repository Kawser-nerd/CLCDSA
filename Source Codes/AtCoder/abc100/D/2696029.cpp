#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>

using T = std::tuple<long long int, long long int, long long int>;
const int MAX_N = 1000;
const int MAX_M = 1000;

T operator+(const T& a, const T& b) {
  return std::make_tuple(
    std::get<0>(a) + std::get<0>(b),
    std::get<1>(a) + std::get<1>(b),
    std::get<2>(a) + std::get<2>(b)
  );
}

long long int evaluate(T t) {
  return std::abs(std::get<0>(t)) + std::abs(std::get<1>(t)) + std::abs(std::get<2>(t));
}

int main() {
  int N, M;
  std::cin >> N >> M;

  std::vector<T> inputs;

  for (int i = 0; i < N; i++) {
    long long int x, y, z;
    std::cin >> x >> y >> z;

    inputs.push_back(std::make_tuple(x, y, z));
  }

  long long int answer = 0;

  for (int i = -1; i <= 1; i += 2) {
    for (int j = -1; j <= 1; j += 2) {
      for (int k = -1; k <= 1; k += 2) {
        sort(inputs.begin(), inputs.end(), [&](const T&a, const T& b) {
          long long int va = i * std::get<0>(a) + j * std::get<1>(a) + k * std::get<2>(a);
          long long int vb = i * std::get<0>(b) + j * std::get<1>(b) + k * std::get<2>(b);

          return va < vb;
        });

        T c = accumulate(inputs.begin(), inputs.begin() + M, T(), [](const T& prev, const T& current) {
          return std::make_tuple(
            std::get<0>(prev) + std::get<0>(current),
            std::get<1>(prev) + std::get<1>(current),
            std::get<2>(prev) + std::get<2>(current)
          );
        });

        answer = std::max(answer, evaluate(c));
      }
    }
  }

  std::cout << answer << std::endl;
}
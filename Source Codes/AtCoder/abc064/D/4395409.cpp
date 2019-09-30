#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  char buf[128];
  scanf("%s", buf);
  std::string S = buf;

  std::vector<int> bal(N+1);
  for (size_t i = 0; i < N; ++i)
    bal[i+1] = bal[i] + ((S[i] == '(')? +1:-1);

  int min = *std::min_element(bal.begin(), bal.end());
  printf("%s%s%s\n",
         std::string(-min, '(').c_str(),
         S.c_str(), std::string(-min+bal[N], ')').c_str());
}
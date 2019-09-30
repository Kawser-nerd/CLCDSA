#include <iostream>

int main(){
  int n;
  int c[30001];
  int p[30001], dp[30001], max, longest;
  std::cin >> n;
  for(int i = 0; i < n; i++){
    std::cin >> c[i];
    p[c[i]] = i;
  }

  for(int i = 1; i <= n; i++){
    max = 0;
    for(int j = 0; j < p[i]; j++){
      if(c[j] < i && dp[c[j]] > max) max = dp[c[j]];
    }
    dp[i] = max + 1;
    if(dp[i] > longest) longest = dp[i];
  }
  std::cout << n - longest << std::endl;
}
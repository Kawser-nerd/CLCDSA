#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <time.h>     
using namespace std;
typedef long long int ll;
char S_c[1000000];
int main(int argc, char const *argv[]) {

  scanf("%s", S_c);
  size_t N = sizeof(S_c) / sizeof(S_c[0]);
  string S(S_c, N);
  vector<int> black_left{0};
  for (int i = 1; i < N; i++) {
    if (S[i - 1] == 'B') {
      black_left.push_back(black_left[i-1]+1);
    }else{
      black_left.push_back(black_left[i-1]);
    }
  }
  ll ans=0;
  for (int i = 1; i < N; i++) {
    if (S[i] == 'W') {
      ans+=black_left[i];
    }
  }
  cout << ans << endl;

  return 0;
}
#include <iostream>
using namespace std;
int main(void)
{
  uint64_t N, M;
  cin >> N >> M;
  uint64_t n = min(N, M);
  uint64_t m = max(N, M);
  if(n == 1 && m == 1) cout << 1 << endl;
  else if(n == 1) cout << N*M - 2 << endl;
  else cout << N*M - (2*M + 2*N - 4) << endl;
  
  return 0;
}
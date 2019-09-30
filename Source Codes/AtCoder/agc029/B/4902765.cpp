#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <bitset>
#include <algorithm>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N, count, ans=0, reg, reg2;
  std::cin >> N;
  std::vector<int> A(N);
  std::vector<int> li(N, 0);
  range(i, N) std::cin >> A[i];
  sort(A.begin(), A.end());

  for(int i=N-1;i>=0;i--){
    int a = lower_bound(A.begin(), A.end(), A[i]) - A.begin();
    int b = upper_bound(A.begin(), A.end(), A[i]) - A.begin();
    if(li[a] >= b - a) continue;
    count = 0;
    reg = A[i];

    while(reg >= 2){
      reg = reg >> 1;
      count++;
    }
    range(j, count+1) reg = reg << 1;

    reg2 = A[i];
    li[a]++;
    if(binary_search(A.begin(), A.end(), reg - reg2)){
      int mm = lower_bound(A.begin(), A.end(), reg - reg2) - A.begin();
      int m = upper_bound(A.begin(), A.end(), reg - reg2) - A.begin();
      if(li[mm] >= m - mm) continue;
      li[mm]++;
      ans++;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
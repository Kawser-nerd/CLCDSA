#include <iostream>
#include <string>
#include <vector>
#include <deque>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
typedef long long int ll;
using namespace std;
std::vector<int> yaku(101, 0);

int aaa(int a){
  int num=0;
  ranges(ii, 2, 101){
    if(yaku[ii]>=a-1) num+=1;
  }
  return num;
}

int main(int argc, char const *argv[]) {
  int N;
  std::cin >> N;
  ll temp, ans=0;
  ranges(i, 1, N+1){
    temp = i;
    ranges(j, 2, N+1){
      while(temp % j == 0){
        yaku[j]++;
        temp /= j;
      }
    }
  }
  ans = aaa(75) + aaa(25) * (aaa(3) - 1) + aaa(15) * (aaa(5) - 1) +(aaa(5) * (aaa(5)-1) * (aaa(3) - 2)/2);
  std::cout << ans << '\n';
  return 0;
}
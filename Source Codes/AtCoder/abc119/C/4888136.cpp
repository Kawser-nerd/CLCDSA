#include <iostream>
#include <string>
#include <vector>
#define range(i,r) for(int i=0;i<r;i++)
#define INF 1e9
using namespace std;
std::vector<int> L;
int N, A, B, C;
int dfs(int cur, int a, int b, int c){
  if(cur == N){
    if(min(a, min(b, c)) > 0){
      return abs(a - A) + abs(b - B) + abs(c - C) - 30;
    }else{
      return INF;
    }
  }
  int ret0 = dfs(cur + 1, a, b, c);
  int ret1 = dfs(cur + 1, a + L[cur], b, c) + 10;
  int ret2 = dfs(cur + 1, a, b + L[cur], c) + 10;
  int ret3 = dfs(cur + 1, a, b, c + L[cur]) + 10;
  return min(ret0, min(ret1, min(ret2, ret3)));
}
int main(int argc, char const *argv[]) {
  std::cin >> N >> A >> B >> C;
  range(i,N) {
    int temp;
    std::cin >> temp;
    L.push_back(temp);
  }
  std::cout << dfs(0, 0, 0, 0) << '\n';
  return 0;
}
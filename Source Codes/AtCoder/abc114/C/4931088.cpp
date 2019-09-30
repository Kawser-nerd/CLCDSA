#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
typedef long long int ll;
using namespace std;
std::vector<int> lis;
std::vector<int> lis2;
std::vector<int> lis3;

void dfs(int e, int num){
  if(num!=0) lis.push_back(num);
  if(num >= 333333333) return;
  dfs(e * 10, num + e * 3);
  dfs(e * 10, num + e * 5);
  dfs(e * 10, num + e * 7);
}
void dfs2(int e, int num){
  if(num!=0) lis2.push_back(num);
  if(num >= 333333333) return;
  dfs2(e * 10, num + e * 3);
  dfs2(e * 10, num + e * 5);
}
void dfs4(int e, int num){
  if(num!=0) lis2.push_back(num);
  if(num >= 333333333) return;
  dfs4(e * 10, num + e * 3);
  dfs4(e * 10, num + e * 7);
}
void dfs5(int e, int num){
  if(num!=0) lis2.push_back(num);
  if(num >= 333333333) return;
  dfs5(e * 10, num + e * 7);
  dfs5(e * 10, num + e * 5);
}
void dfs3(int e, int num){
  if(num!=0) lis3.push_back(num);
  if(num >= 333333333) return;
  dfs3(e * 10, num + e * 3);
}
void dfs6(int e, int num){
  if(num!=0) lis3.push_back(num);
  if(num >= 333333333) return;
  dfs6(e * 10, num + e * 5);
}
void dfs7(int e, int num){
  if(num!=0) lis3.push_back(num);
  if(num >= 333333333) return;
  dfs7(e * 10, num + e * 7);
}

int main(int argc, char const *argv[]) {
  int N;
  std::cin >> N;
  dfs(1, 0);
  dfs2(1, 0);
  dfs3(1, 0);
  dfs4(1, 0);
  dfs5(1, 0);
  dfs6(1, 0);
  dfs7(1, 0);
  sort(lis.begin(), lis.end());
  sort(lis2.begin(), lis2.end());
  sort(lis3.begin(), lis3.end());
  int maxx = upper_bound(lis.begin(), lis.end(), N) - lis.begin();
  int maxx2 = upper_bound(lis2.begin(), lis2.end(), N) - lis2.begin();
  int maxx3= upper_bound(lis3.begin(), lis3.end(), N) - lis3.begin();
  std::cout << maxx - maxx2 + maxx3<< '\n';
  return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int ll;
ll N;
int main(int argc, char const *argv[]) {
  cin >> N;
  ll x = 1;
  for(int i=1;i<=N;i++){
    x=(i*x)%1000000007;
  }
  cout<<x<<endl;
  return 0;
}
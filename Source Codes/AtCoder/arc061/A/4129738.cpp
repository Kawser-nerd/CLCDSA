#include <iostream>
#include <string>

typedef long long int ll;
using namespace std;


ll dfs(ll n, string S){
  // ????
  int len = S.size();
  if(len == 0) {
    return n;
  }

  // ????????
  ll sum = 0;
  for (int i = 1; i <= len; ++i) {
    ll m = stoll(S.substr(0, i));
//    cout << m << endl;
    sum += dfs(n+m, S.substr(i, len - i));
  }

  return sum;
}

int main() {

  // ??
  string S;
  cin >> S;


  // ??
  cout << dfs(0, S) << endl;

  return 0;

}
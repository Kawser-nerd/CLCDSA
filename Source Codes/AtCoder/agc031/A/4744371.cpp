//https://atcoder.jp/contests/agc031/tasks/agc031_a
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int mod = 1e9 + 7;
int alphabet[30];
long long ans = 1;

int main(int argc, char const *argv[]) {
  int N;
  string S;
  cin >> N >> S;
  for (int i=0; i<S.size(); i++){
    alphabet[S[i] - 'a' + 1]++;
  }
  for (int i=0; i<30; i++){
    ans = ans * (alphabet[i]+1);
    ans = ans%mod;
  }
  cout<<ans-1<<endl;
  return 0;
}
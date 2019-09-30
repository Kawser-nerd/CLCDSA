#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll DIV = 1e9+7;


int main(){
  ll N;
  cin >> N;
  string S;
  cin >> S;
  ll c[26];
  for(int i = 0; i < 26; i++){
  c[i] = 0;
  }
  for(int i = 0;i< N;++i){
  c[S[i] - 'a']++;
  }
  ll ans = 1;
  for(int i=0;i< 26; i++){
  ans *= c[i] + 1;
  ans %= DIV;
  }
  ans--;
  ans %= DIV;
  cout << ans << endl;
}
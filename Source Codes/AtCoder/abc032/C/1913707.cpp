#include <iostream>
#include <vector>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  vector<int> s(N);
  for(int i = 0; i < N; ++i){
    cin >> s[i];
    if(s[i] == 0){
      cout << N << endl;
      return 0;
    }
  }
  int ans = 0, l = -1;
  long long int t = 1;
  for(int i = 0; i < N; ++i){
    t *= s[i];
    while(t > K && l < i){
      ++l;
      t /= s[l];
    }
    ans = max(ans,i-l);
  }
  cout << ans << endl;
  return 0;
}
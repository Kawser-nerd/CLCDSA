#include <iostream>
using namespace std;
int main(){
  long long int N;
  cin >> N;
  long long int t = 1, c = 0;
  while(t <= N){
    t *= 2;
    ++c;
  }
  t = 1;
  for(int i = 0; i < c-1; ++i){
    t *= 2;
    if((c-1-i)%2 == 0) t += 1;
  }
  string ans[] = {"Takahashi", "Aoki"};
  if(t > N) cout << ans[1 - c%2] << endl;
  else cout << ans[c%2] << endl;

  return 0;
}
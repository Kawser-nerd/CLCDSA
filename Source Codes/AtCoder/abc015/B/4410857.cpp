#include<iostream>
#include <vector>
#include<string>

using namespace std;

int main(){
  int N, cnt=0;
  cin >> N;
  vector <int> a(N);
  int sum=0, ans=0;
  for(int i=0; i < N; i++){
      cin >> a[i];
      if(a[i] > 0){
          sum += a[i];
          cnt++;
      }
  }
  ans = sum / cnt;
  if(sum % cnt)ans++;
  cout << ans << endl;
}
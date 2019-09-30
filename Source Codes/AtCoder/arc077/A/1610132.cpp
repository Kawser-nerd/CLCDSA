#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;
typedef pair<int, int> P;

int ab = 5;
int solve(int a_){
    return a_ + 1;
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(false);
   
  int a[200000] = {};
  int ans[200000] = {};
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int kib = 0;
  int gub = 0;
  int ba = 0;
  if(n%2==0){
    ba = n /2;
    kib = ba + 1;
    gub = ba - 1;
    ans[ba] = a[0];
    for(int i = 1; i < n; i++){
      if(i % 2 == 1){
        ans[gub] = a[i];
        gub--;
      }else{
        ans[kib] = a[i];
        kib++;
      }
    }
  }else{
    ba = n / 2;
    kib = ba - 1;
    gub = ba + 1;
    ans[ba] = a[0];
    for(int i = 1; i < n; i++){
      if(i % 2 == 1){
        ans[gub] = a[i];
        gub++;
      }else{
        ans[kib] = a[i];
        kib--;
      }
    }
  }

  for(int i = 0; i < n-1; i++){
    cout << ans[i] << ' ';
  }
  cout << ans[n-1] << '\n';

   return 0;
}
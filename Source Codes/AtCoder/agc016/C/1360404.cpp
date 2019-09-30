#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;


Int H, W, h, w;
Int sum;
Int ans[540][540];
int main(){
  cin >> H >> W >> h >> w;
  if(H % h == 0 && W % w == 0){
    cout << "No" << endl;
    return 0;
  }
  Int a = 999999999 / (h*w-1);
  Int b = a * (h * w - 1) + 1;
  for(Int i = 0;i < H;i++){
    for(Int j = 0;j < W;j++){
      if(i % h == h-1 && j % w == w-1)ans[i][j] = -b;
      else ans[i][j] = a;
      sum += ans[i][j];
    }
  }
  if(sum <= 0){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  for(Int i = 0;i < H;i++){
    for(Int j = 0;j < W;j++){
      cout << ans[i][j] << " ";
    }cout << endl;
  }
  return 0;
}
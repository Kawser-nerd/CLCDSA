#include <iostream>
#include <vector>

using namespace std;
#define ll long long int
int main(){
  int H,W,h,w;
  cin >> H >> W >> h >> w;
  int ans = ( H - h ) * ( W - w );
  cout << ans << endl;
  
  return 0;
}
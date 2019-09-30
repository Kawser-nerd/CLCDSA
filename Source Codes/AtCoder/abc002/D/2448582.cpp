#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
  int N,M;
  cin >> N >> M;
  bool pair[12][12] = {};
  REP(i,M) {
    int x, y;
    cin >> x >> y;
    pair[x-1][y-1] = pair[y-1][x-1] = true;
  }

  int ans = 0;
  for (int bit=1<<N; bit--; ) {
    int t = bitset<32>(bit).count();
    if (t <= ans) continue;
    bool flg = true;
    for(int j=0; j<N; j++) {
      for(int k=0; k<j; k++){
        if(bit >> j & bit >> k & 1 && !pair[j][k]){
          flg = false;
        }
      }
    }
    if(flg) ans = t;
  }
  cout << ans << endl;
  return 0;
}
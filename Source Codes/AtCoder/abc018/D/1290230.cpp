#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int n, m, p, q, r;
  cin >> n >> m >> p >> q >> r;

  int x, y, z;
  vector<vector<pair<int, int> > > chocolate(n);
  for(int i = 0; i < r; i++){
    cin >> x >> y >> z;
    chocolate[x - 1].push_back(make_pair(z, y - 1));
  }

  int ans = 0;
  vector<int> dp(1 << n, 0);
  for(int i = 0; i < (1 << n); i++){
    // ?????P??????
    if(__builtin_popcount(i) == p){
      vector<int> boy(m, 0);
      for(int j = 0; j < n; j++){
        if((i & (1 << j)) != 0){
          // ?????????J??????????
          // boy?????????
          for(int k = 0; k < (int)chocolate[j].size(); k++)
            boy[chocolate[j][k].second] += chocolate[j][k].first;
        } 
      }
      // boy?????????
      sort(boy.begin(), boy.end());
      reverse(boy.begin(), boy.end());

      // ??Q??????????
      int group_point = 0;
      for(int k = 0; k < q; k++){ group_point += boy[k]; }

      // ????
      ans = max(ans, group_point);
    }
  }

  // ??
  cout << ans << endl;
  return 0;
}
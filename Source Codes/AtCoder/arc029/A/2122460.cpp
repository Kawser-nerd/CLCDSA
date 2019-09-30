#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int N; 
  cin >> N;
  vector<int> t(N);
  for(int i=0; i<N; i++) cin >> t[i];

  int left, right, res=99999999;

  for (int i=0; i< pow(2, t.size()); i++){
    left = 0;
    right = 0;

    for (int k=0; k< t.size(); k++) {
      if(i & (1 << k)) left += t[k];
      else right += t[k];
    }
    res = min(res, max(left, right));
  }
  cout << res << endl;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;

  vector<vector<bool>> fri(N, vector<bool>(N, false));
  int tmpa, tmpb;
  for (int i=0; i<M; i++) {
    cin >> tmpa >> tmpb;
    fri[tmpa-1][tmpb-1] = true;
    fri[tmpb-1][tmpa-1] = true;
  }

  for (int i=0; i<N; i++) {
    fri[i][i] = true;
  }

  // pair ?????
  // ??????????????????true???

  int res = 1;
  bool non = false;
  for (int i=0; i<pow(2, N); i++) {
    vector<int> list;
    non = false;
    for (int k=0; k<N; k++) {
      if (i& 1<<k) list.push_back(k);
    }

    for (int k=0; k<list.size(); k++) {
      for (int l=0; l<list.size(); l++) {
        if (!fri[list[k]][list[l]]) {

          non = true;
          break;
        }
      }
      if (k == list.size() - 1 && !non) { 
        res = max(res, (int)list.size());
      }
    }
  }
  cout << res << endl;
}
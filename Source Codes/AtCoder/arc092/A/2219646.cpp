#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> red(N*2+1, -1);
  vector<int> blue(N*2+1, -1);
  int a, b;
  for (int i=0; i<N; i++) {
    cin >> a >> b;
    red[a] = b;
  }
  for (int i=0; i<N; i++) {
    cin >> a >> b;
    blue[a] = b;
  }

  int res = 0;
  int tmp=-1,tmpi=0;


  for (int i=0; i<red.size(); i++) {
    if (blue[i] == -1) continue;
    tmp = INT_MAX;
    tmpi = INT_MAX;
    for (int k=0; k<i; k++) {
      if (red[k] == -1) continue;
      if (red[k] < blue[i]) {
        if (tmp > blue[i] - red[k]) {
          tmp = blue[i] - red[k];
          tmpi = k;
        }
      }
    }
    if (tmpi != INT_MAX)  {
      red[tmpi] = -1;
      res++;
    }
  }
  cout << res << endl;
}
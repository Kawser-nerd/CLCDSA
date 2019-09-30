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
  vector<long> v(N);
  for (int i=0; i<N; i++) cin >> v[i];

  sort(v.begin(), v.end());
  if (N==2) {
    cout << v[1] << " " << v[0] << endl;
    return 0;
  }

  int half = v[N-1]/2;
  int lc = lower_bound(v.begin(), v.end()-1, half) - v.begin();

  if (abs(((double)v[N-1]/2) - v[lc]) > abs(((double)v[N-1]/2) - v[lc-1]))
    lc = lc - 1;

  cout << v[N-1] << " " << v[lc] << endl;
}
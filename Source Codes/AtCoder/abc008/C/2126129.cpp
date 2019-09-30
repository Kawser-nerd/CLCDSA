#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> v(N, 0);

  for (int i=0; i<N; i++)
    cin >> v[i];

  int n =0;
  double res = 0;
  for (int i=0; i<N; i++) {
    n = 0;
    for (int k=0; k<N; k++) {
      if (i == k) continue;
      if (v[i]%v[k] == 0) n++; 
    }
    if (n % 2== 1) res += 0.5;
    else res += (double)(n+2)/(2*n + 2);
  }
  cout << setprecision(10) << res << endl;
}
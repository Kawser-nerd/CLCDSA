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
  vector<int> v(N);
  for (int i=0; i<N; i++) cin >> v[i];

  if (N == 2) {
    cout << v[1] << endl;
    cout << v[0] << endl;
    return 0;
  }

  vector<int> sorted_v(v);
  sort(sorted_v.begin(), sorted_v.end());

  int one = sorted_v[(N/2) - 2];
  int two = sorted_v[(N/2) - 1];
  int three = sorted_v[N/2];
  int four = sorted_v[N/2 + 1];

  for (int i=0; i<N; i++) {
    if (v[i] >= three) {
      cout << two << endl;
    } else if (v[i] <= two) {
      cout << three << endl;
    }
  }
}
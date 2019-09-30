#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int txa, tya, txb, tyb, T, V, n;
  cin >> txa >> tya >> txb >> tyb >> T >> V >> n;
  vector<double> x(n);
  vector<double> y(n);
  for (int i=0; i<n; i++) cin >> x[i] >> y[i];

  double lens, lene;
  for (int i=0; i<n; i++) {
    lens = sqrt(pow(x[i] - txa, 2)+pow(y[i] - tya, 2));
    lene = sqrt(pow(x[i] - txb, 2)+pow(y[i] - tyb, 2));

    if (V*T >= lens+lene) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
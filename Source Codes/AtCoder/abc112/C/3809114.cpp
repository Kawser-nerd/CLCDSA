#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
  int N;
  cin >> N;
  int x[110];
  int y[110];
  int h[110];
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    cin >> y[i];
    cin >> h[i];
  }

  for (int i = 0; i < N; i++) {
    if (h[i]) {
      swap(x[0], x[i]);
      swap(y[0], y[i]);
      swap(h[0], h[i]);
      break;
    }
  }
	

  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      bool flag = true;
      int d_x = abs(x[0] - i);
      int d_y = abs(y[0] - j);
      int H = h[0] + d_x + d_y;
      for (int k = 1; k < N; k++) {
	if (h[k] != max(H - abs(x[k] - i) - abs(y[k] - j), 0)) {
	  flag = false;
	  break;
	}
      }
      if (flag) {
	cout << i << " " << j << " " << H << endl;
	return 0;
      }
    }
  }
  
}
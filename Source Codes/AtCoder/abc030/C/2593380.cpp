#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;

  vector<int> a(N);
  vector<int> b(M);

  for(int i=0; i<N; i++) cin >> a[i];
  for(int i=0; i<M; i++) cin >> b[i];

  int now_t = 0;
  bool now_a = true;
  int i = 0;
  int res = 0;

  while (true) {
    if (now_a && now_t > a[N-1]) break;
    if (!now_a && now_t > b[M-1]) break;
 
    if (now_a) {
      i = lower_bound(a.begin(), a.end(), now_t) - a.begin();
      now_t = a[i] + X;
    } else {
      i = lower_bound(b.begin(), b.end(), now_t) - b.begin();
      now_t = b[i] + Y;
      res++;
    }
    now_a = !now_a;
  }

  cout << res << endl;
}
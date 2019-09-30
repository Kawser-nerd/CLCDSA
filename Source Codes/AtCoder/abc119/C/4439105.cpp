#include <iostream>
#include <cmath>

using namespace std;

const int INF = 1e9;


int calc_mp(int *take, int a, int b, int c) {
  if (take[0] == 0 || take[1] == 0 || take[2] == 0) {
    return INF;
  }

  return std::abs(take[0]-a) + std::abs(take[1]-b) + std::abs(take[2]-c);
}
void copy(int *l, int *m) {
  m[0] = l[0];
  m[1] = l[1];
  m[2] = l[2];
}

int mp_min = INF;
int search(int *l, int n, int i, int *take, int a, int b, int c, int tmp_mp) {
  if (i == n) {
    int mp = calc_mp(take, a, b, c) + tmp_mp - 30;
    if (mp < mp_min) {
      mp_min = mp;
    }
    return 0;
  }
  int li = l[i];

  search(l, n, i+1, take, a, b, c, tmp_mp);
  int t2[3];
  copy(take, t2);
  t2[0] += li;
  search(l, n, i+1, t2, a, b, c, tmp_mp + 10);
  int t3[3];
  copy(take, t3);
  t3[1] += li;
  search(l, n, i+1, t3, a, b, c, tmp_mp + 10);

  int t4[3];
  copy(take, t4);
  t4[2] += li;
  search(l, n, i+1, t4, a, b, c, tmp_mp + 10);
  return mp_min;
}



int main() {
  ios::sync_with_stdio(false);
  int n, a, b, c;
  cin>> n >> a >> b >> c;
  int l[8];
  for (int i=0; i<n; i++) {
    int li;
    cin >> li;
    l[i] = li;

  }
  int take[3] = {0};
  cout <<  search(l, n, 0, take, a, b, c, 0);
}
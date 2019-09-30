#include <iostream>
using namespace std;

#define INF 100000

int main(int argc, char *argv[]) {
  int c[100000];
  int d[100000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    d[i] = INF;
  }
  for (int i = 0; i < n; i++) {
    *lower_bound(d, d + n, c[i]) = c[i];
  }
  cout << count(d, d + n, INF) << endl;
  return 0;
}
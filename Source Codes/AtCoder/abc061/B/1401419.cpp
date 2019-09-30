#include <iostream>
using namespace std;

const int MAX_N = 50;
int v[MAX_N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int p, q;
    cin >> p >> q;
    v[p-1]++;
    v[q-1]++;
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] << endl;
  }
}
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a[100010];
  set<int> b;
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
    b.insert(a[i]);
  }
  map<int, int> M;
  int cnt = 0;
  for (auto x : b) {
    M[x] = cnt++;
  }
  for (auto i = 0; i < N; i++) {
    cout << M[a[i]] << endl;
  }
}
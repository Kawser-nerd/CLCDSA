#include <iostream>
using namespace std;


int main() {
  int N;
  cin >> N;
  int sup = -1;
  int inf = 1001;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    sup = max(sup, a);
    inf = min(inf, a);
  }
  cout << sup - inf << endl;
}
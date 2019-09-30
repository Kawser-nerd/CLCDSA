#include <iostream>
using namespace std;

int main() {
  int n, a[110] = {0};
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int count = 0;
  for(int i = 0; i < n - 1; i++){
    if(a[i] == a[i + 1]){
      count += 1;
      a[i + 1] = 0;
    }
  }

  cout << count << endl;
  return 0;
}
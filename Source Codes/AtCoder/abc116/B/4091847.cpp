#include <iostream>
using namespace std;

int a[1000005], cnt = 1;
int main(){
  int s;
  cin >> s;
  while (true){
    if (a[s]){
      cout << cnt << '\n';
      return 0;
    }
    cnt++;
    a[s] = 1;
    if (s & 1) s = 3 * s + 1;
    else s = s/2;
  }
  return 0;
}
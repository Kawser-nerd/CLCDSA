#include <iostream>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  string ans;
  if (A + B > C + D)
    ans = "Left";
  else if (A + B < C + D)
    ans = "Right";
  else
    ans = "Balanced";

  cout << ans << endl;
  return 0;
}
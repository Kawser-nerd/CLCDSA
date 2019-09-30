#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;

  int count = 0;
  bool ans  = true;
  if (S[0] != 'A')
    ans = false;
  for (int i = 1; i < S.size(); i++) {
    if (isupper(S[i])) {
      if (i == 1 || i == S.size() - 1 || S[i] != 'C')
        ans = false;
      else
        count++;
    }
  }
  if (count != 1)
    ans = false;
  if (ans)
    cout << "AC" << endl;
  else
    cout << "WA" << endl;
  return 0;
}
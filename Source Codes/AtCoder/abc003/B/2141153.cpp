#include <iostream>
using namespace std;
#define print(var) cout << var << endl

int main() {
  string S, T;
  cin >> S >> T;
  bool flag = true;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] != T[i]) {
      flag = false;
      if (S[i] == '@' && (T[i] == 'a' || T[i] == 't' || T[i] == 'c' || T[i] == 'o' || T[i] == 'd' || T[i] == 'e' || T[i] == 'r'))
        flag = true;
      if (T[i] == '@' && (S[i] == 'a' || S[i] == 't' || S[i] == 'c' || S[i] == 'o' || S[i] == 'd' || S[i] == 'e' || S[i] == 'r'))
        flag = true;
      if (!flag)
        break;
    }
  }
  if (flag)
    cout << "You can win" << endl;
  else
    cout << "You will lose" << endl;
}
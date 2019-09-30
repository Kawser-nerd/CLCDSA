#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  string S, T;
  string atcoder = "atcoder";

  cin >> S >> T;

  bool can_win = true;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == T[i]) continue;
    if (!(S[i] == '@' || T[i] == '@')) {
      can_win = false;
      break;
    }
    if (!(atcoder.find(S[i]) != string::npos || atcoder.find(T[i]) != string::npos)) {
      can_win = false;
      break;
    }
  }

  if(can_win) {
    cout << "You can win" << endl;
  } else {
    cout << "You will lose" << endl;
  }
}
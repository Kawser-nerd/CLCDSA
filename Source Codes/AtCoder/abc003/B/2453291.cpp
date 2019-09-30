#include <string>
#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

bool judge(char c) {
  if (c=='a'||c=='t'||c=='c'||c=='o'||c=='d'||c=='e'||c=='r')
    return true;
  else
    return false;
}

int main()
{
  string S,T;
  bool flg = true;
  string str = "atcoder";
  cin >> S >> T;

  REP(i,S.size())
  {
    if (S[i] == T[i]) {
      continue;
    } else if (!flg) {
      break;
    } else {
      flg = false;
      if (S[i] == '@') flg = judge(T[i]);
      if (T[i] == '@') flg = judge(S[i]);
    }
  }

  cout << (flg ? "You can win" : "You will lose") << endl;
  return 0;
}
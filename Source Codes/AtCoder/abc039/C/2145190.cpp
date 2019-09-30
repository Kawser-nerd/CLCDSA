#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  string s;
  cin >> s;

  int a = 0;
  int t = 0;
  for (int i=0; i<s.length(); i++) {
    if (s[i] == s[i+1]) {
      a = i;
      if (s[i+2] == s[i+4] && s[i+4] == s[i+6]) t = 1;
      a /= 2;
      break;
    }
  }


  vector<string> d = {"Mi", "Re", "Do"};
  vector<string> dd = {"Si", "La", "So", "Fa"};
  if (t==1) cout << d[a] << endl;
  else cout << dd[a] << endl;
}
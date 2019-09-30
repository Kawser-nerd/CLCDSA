#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool won(const vector<string>& v, char c) {
  for(int r = 0; r < 4; ++r) {
    bool b = true;
    for(int i = 0; i < 4; ++i)
      if(v[r][i] != c && v[r][i] != 'T')
	b = false;
    if(b) return true;
  }
  for(int r = 0; r < 4; ++r) {
    bool b = true;
    for(int i = 0; i < 4; ++i)
      if(v[i][r] != c && v[i][r] != 'T')
	b = false;
    if(b) return true;
  }

  bool b = true;
  for(int i = 0; i < 4; ++i)
    if(v[i][i] != c && v[i][i] != 'T')
      b = false;
  if(b) return true;
  for(int i = 0; i < 4; ++i)
    if(v[i][3-i] != c && v[i][3-i] != 'T')
      return false;
  return true;
}
int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    vector<string> v(4);
    for(int i = 0; i < 4; ++i)
      cin >> v[i];
    if(won(v, 'X'))
      cout << "Case #" << t << ": X won" << endl;
    else if(won(v, 'O'))
      cout << "Case #" << t << ": O won" << endl;
    else {
      bool b = false;
      for(int r = 0; r < 4; ++r)
	for(int c = 0; c < 4; ++c)
	  if(v[r][c] == '.')
	    b = true;
      if(b)
	cout << "Case #" << t << ": Game has not completed" << endl;
      else
	cout << "Case #" << t << ": Draw" << endl;
    }
  }
}

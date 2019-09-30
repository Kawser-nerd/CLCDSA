#include <iostream>
#include <string>
using namespace std;

int jump(int& pos, const string s, const int len) {
  int stack = 1;
  while (stack > 0) {
    pos++;
    if (pos >= len) break;
    // cout << "pos: " << pos << ", stack: " << stack << endl;
    if (s[pos] == '(') {
      stack++;
    }
    else {
      stack--;
    }
  }
  // cout << "last:: pos: " << pos << ", stack: " << stack << endl;
  return stack;
}


int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  int pos = 0;
  int lp = 0, rp = 0;
  while (pos < N) {
    // cout << "pos: " << pos << endl;
    if (s[pos] == '(') {
      rp = jump(pos, s, N);
    }
    else {
      lp++;
    }
    pos++;
  }
  // cout << "lp:" << lp << ", rp:" << rp << endl;
  for (int i = 0; i < lp; i++) {
    cout << '(';
  }
  cout << s;
  for (int i = 0; i < rp; i++) {
    cout << ')';
  }
}
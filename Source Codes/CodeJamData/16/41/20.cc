#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string doP(int n, int& r, int& p, int& s);
string doS(int n, int& r, int& p, int& s);
string doR(int n, int& r, int& p, int& s) {
  if (n == 0) { r = 1; p = 0; s = 0; return "R"; }
  int r2, p2, s2;
  string a = doP(n-1, r, p, s);
  string b = doS(n-1, r2, p2, s2);
  r += r2; p += p2; s += s2;
  if (a > b) swap(a, b);
  return a+b;
}

string doP(int n, int& r, int& p, int& s) {
  if (n == 0) { r = 0; p = 1; s = 0; return "P"; }
  int r2, p2, s2;
  string a = doS(n-1, r, p, s);
  string b = doR(n-1, r2, p2, s2);
  r += r2; p += p2; s += s2;
  if (a > b) swap(a, b);
  return a+b;
}

string doS(int n, int& r, int& p, int& s) {
  if (n == 0) { r = 0; p = 0; s = 1; return "S"; }
  int r2, p2, s2;
  string a = doR(n-1, r, p, s);
  string b = doP(n-1, r2, p2, s2);
  r += r2; p += p2; s += s2;
  if (a > b) swap(a, b);
  return a+b;
}

int main() {
  int N, R, P, S, T, prob=1;
  for (cin >> T; T--;) {
    cin >> N >> R >> P >> S;
    cout << "Case #" << prob++ << ": ";

    int r, p, s;
    string Rs = doR(N, r, p, s);
    if (r != R || p != P || s != S) Rs = "x";
    string Ps = doP(N, r, p, s);
    if (r != R || p != P || s != S) Ps = "x";
    string Ss = doS(N, r, p, s);
    if (r != R || p != P || s != S) Ss = "x";
    string ret = min(Rs, min(Ps, Ss));
    if (ret == "x") {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << ret << endl;
    }
  }
}

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef __int64 ll;

///////////////////////////////////////////////////////////////////////////////////////////////////
// Parsing
vector<string> Split(const string &s, const string &delimiters = " ") {
  vector<string> result;
  string temp;
  for (int i = 0; i < (int)s.size(); i++) {
    if (delimiters.find(s[i]) == string::npos) {
      temp += s[i];
    } else {
      if (temp.size() > 0)
        result.push_back(temp);
      temp = "";
    }
  }
  if (temp.size() > 0)
    result.push_back(temp);
  return result;
}
vector<string> SplitDelimiters(const string &s, const string &delimiters = " ") {
  vector<string> result;
  string temp;
  for (int i = 0; i < (int)s.size(); i++) {
    if (delimiters.find(s[i]) == string::npos) {
      if (temp.size() > 0 || result.size() == 0)
        result.push_back(temp);
      temp = "";
    } else {
      temp += s[i];
    }
  }
  result.push_back(temp);
  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Formatting
int gPrecision = -1;
string ToString(bool x) {return (x? "1" : "0");}
string ToString(char ch) {string s; s += ch; return s;}
string ToString(double x) {
  ostringstream out;
  if (gPrecision != -1) {out.precision(gPrecision); out << fixed;}
  out << x;
  string temp = out.str();
  if (temp[0] != '-') // Never return "-0.0000"
    return temp;
  for (int i = 1; i < (int)temp.size(); i++)
    if (temp[i] != '.' && temp[i] != '0')
      return temp;
  return temp.substr(1);
}
string ToString(float x) {return ToString(double(x));}
string ToString(int n) {ostringstream out; out << n; return out.str();}
string ToString(ll n) {ostringstream out; out << n; return out.str();}
string ToString(const string &s) {return s;}
template <class S, class T> string ToString(const pair<S, T> &x) {
  return "(" + ToString(x.first) + "," + ToString(x.second) + ")";
}
template <class S, class T> string ToString(const map<S, T> &x, const string &delim = ",") {
  string s = "{";
  for (map<S, T>::const_iterator it = x.begin(); it != x.end(); ++it)
    s += (it == x.begin()? "" : delim) + ToString(it->first) + "->" + ToString(it->second);
  return s + "}";
}
template <class T> string ToString(const set<T> &x, const string &delim = ",") {
  string s = "{";
  for (set<T>::const_iterator it = x.begin(); it != x.end(); ++it)
    s += (it == x.begin()? "" : delim) + ToString(*it);
  return s + "}";
}
template <class T> string ToString(const vector<T> &x, const string &delim = ",") {
  string s = "(";
  for (int i = 0; i < (int)x.size(); i++)
    s += (i == 0? "" : delim) + ToString(x[i]);
  return s + ")";
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Tools
///////////////////////////////////////////////////////////////////////////////////////////////////

ifstream in("in.txt");
ofstream out("out.txt");
void SolveCase();
int main() {
  int num_cases;
  in >> num_cases;
  for (int i = 0; i < num_cases; i++) {
    out << "Case #" << (i+1) << ": ";
    SolveCase();
    cout << "Done case #" << (i+1) << " of " << num_cases << endl;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

bool IsWon(int pos, int been_pos, const vector<string> &board, vector<int> &memo) {
  int y = pos / 4, x = pos % 4;
  if (memo[been_pos*16+pos] != -1)
    return memo[been_pos*16+pos] == 1;
  bool is_winnable = false;
  for (int dy = -1; dy <= 1; dy++)
    for (int dx = -1; dx <= 1; dx++)
      if (dx != 0 || dy != 0) {
        int x2 = x + dx, y2 = y + dy;
        if (x2 < 0 || y2 < 0 || x2 >= (int)board[0].size() || y2 >= (int)board.size()) continue;
        if (board[y2][x2] != '.') continue;
        int pos2 = y2*4 + x2;
        if ((been_pos & (1<<pos2)) != 0) continue;
        if (!IsWon(pos2, been_pos + (1 << pos), board, memo)) {
          is_winnable = true;
          break;
        }
      }
  memo[been_pos*16+pos] = (is_winnable? 1 : 0);
  return is_winnable;
}

void SolveCase() {
  int max_x, max_y;
  in >> max_y >> max_x;
  vector<string> board(max_y);
  for (int i = 0; i < max_y; i++)
    in >> board[i];
  int kx, ky;
  for (int y = 0; y < (int)board.size(); y++)
    for (int x = 0; x < (int)board[0].size(); x++)
      if (board[y][x] == 'K') {
        ky = y;
        kx = x;
      }
  vector<int> memo(16*(1<<16), -1);
  out << (IsWon(4*ky+kx, 0, board, memo)? "A" : "B") << endl;
}

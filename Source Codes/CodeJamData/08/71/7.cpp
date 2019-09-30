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
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int GetResult(map<string, int> &memo, map<string, vector<string> > &sub_mixes, const string &query) {
  if (memo.count(query))
    return memo[query];
  vector<int> result;
  for (int i = 0; i < (int)sub_mixes[query].size(); i++)
    result.push_back(GetResult(memo, sub_mixes, sub_mixes[query][i]));
  sort(result.begin(), result.end());
  int rv = (int)result.size() + 1;
  for (int i = 0; i < (int)result.size(); i++) {
    int x = (int)result.size() - 1 - i + result[i];
    rv = max(rv, x);
  }
  memo[query] = rv;
  return rv;
}

void SolveCase() {
  map<string, int> memo;
  map<string, vector<string> > sub_mixes;
  int mixes;
  string goal = "";
  in >> mixes;
  for (int i = 0; i < mixes; i++) {
    string query;
    in >> query;
    if (goal == "")
      goal = query;
    int cnt;
    in >> cnt;
    vector<string> x;
    for (int j = 0; j < cnt; j++) {
      string temp;
      in >> temp;
      if (temp[0] >= 'A' && temp[0] <= 'Z')
        x.push_back(temp);
    }
    sub_mixes[query] = x;
  }
  
  out << GetResult(memo, sub_mixes, goal) << endl;
}

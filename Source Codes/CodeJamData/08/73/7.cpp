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
    cout << "Done case #" << (i+1) << endl;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> ToVector(int n, ll code) {
  vector<int> result;
  for (int i = 0; i < n; i++) {
    result.push_back(code % 4);
    code /= 4;
  }
  return result;
}
ll ToCode(const vector<int> &v) {
  ll mask = 1, result = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    result += v[i] * mask;
    mask *= 4;
  }
  return result;
}

void SolveCase() {
  priority_queue<pair<double, ll> > q;
  int M, Q;
  in >> M >> Q;
  double opt = 1;
  vector<vector<double> > choices(Q, vector<double>(4));
  for (int i = 0; i < Q; i++) {
    for (int j = 0; j < 4; j++)
      in >> choices[i][j];
    sort(choices[i].begin(), choices[i].end());
    reverse(choices[i].begin(), choices[i].end());
    opt *= choices[i][0];
  }
  q.push(make_pair(opt, 0));
  set<ll> done;
  done.insert(0);

  double rv = 0;
  for (int i = 0; i < M; i++) {
    if (q.empty())
      break;
    double val = q.top().first;
    vector<int> c = ToVector(Q, q.top().second);
    q.pop();
    rv += val;
    for (int j = 0; j < Q; j++) {
      double new_val = val;
      vector<int> nc = c;
      nc[j]++;
      if (nc[j] == 4 || choices[j][nc[j]] == 0)
        continue;
      new_val *= choices[j][nc[j]] / choices[j][c[j]];
      ll new_code = ToCode(nc);
      if (done.count(new_code))
        continue;
      done.insert(new_code);

      q.push(make_pair(new_val, new_code));
    }
  }
  out << rv << endl;
}

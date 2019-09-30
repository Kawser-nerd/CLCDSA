// misof: I suck, I did not manage to write a fast enough solution in Python :(
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

char memo[11][23456789];

char solve(int x, int b) {
  char &res = memo[b][x];
  if (x==1) return res=1;
  if (res==2) return res=0;
  if (res!=-1) return res;
  res=2;
  int sum=0, y=x;
  while (y) { sum += (y%b)*(y%b); y/=b; }
  return res = solve(sum,b);
}

int main() {
  memset(memo,-1,sizeof(memo));
  int T;
  string line;
  getline(cin,line);
  stringstream(line) >> T;
  for (int t=1; t<=T; ++t) {
    getline(cin,line);
    vector<int> B;
    int x;
    stringstream ss(line);
    while (ss >> x) B.push_back(x);
    sort(B.begin(),B.end());
    reverse(B.begin(),B.end());
    int test = 2;
    while (1) {
      bool ok = true;
      for (int i=0; i<int(B.size()); ++i) if (solve(test,B[i])!=1) { ok=false; break; }
      if (ok) break;
      ++test;
    }
    cout << "Case #" << t << ": " << test << endl;
  }
}

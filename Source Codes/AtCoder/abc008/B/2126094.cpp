#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<string, int> m;
  string tmp;
  for (int i=0; i<n; i++) {
    cin >> tmp;
    if (m[tmp] == 0) {
      m[tmp] = 1;
    } else {
      m[tmp]++;
    }
  }

  string b = "";
  int res = 0;
  for (pair<string, int> a: m) {
    if (b == "") {
      b = a.first;
      res = a.second;
    } else {
      if (res < a.second) {
        b = a.first;
        res = a.second;
      }
    }
  }
  cout << b << endl;
}
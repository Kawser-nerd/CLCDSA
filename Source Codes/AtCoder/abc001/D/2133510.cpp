#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> v(n);
  for(int i=0; i<n; i++) cin >> v[i];


  for (int i=0; i<n; i++) {
    // ?
    if (v[i][3] < '5') v[i][3] = '0';
    if (v[i][3] > '5') v[i][3] = '5';
    //?
    if (v[i][8] > '0' && v[i][8] < '5') v[i][8] = '5';
    if (v[i][8] > '5' && v[i][9] <= '9') {
      v[i][8] = '0';
      v[i][7]++;
      if (v[i][7] == '6') {
        v[i][7] = '0';
        v[i][6]++;
        if (v[i][6] == '9' + 1) {
          v[i][6] = '0';
          v[i][5]++;
        }
      }
    }
  }

  sort(v.begin(), v.end());

  string left = v[0].substr(0, 4);
  string right = v[0].substr(5);
  string tl, tr;
  for (int i=1; i<n; i++) {
    tl = v[i].substr(0,4);
    tr = v[i].substr(5);
    if (left <= tl && tr <= right) continue;
    if (tl <= right) {
      right = tr;
      continue;
    }
    cout << left << "-" << right << endl;
    left = tl;
    right = tr;
  }
  cout << left << "-" << right << endl;
}
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*int nswap(const vector<int>& v) {
  int ret = 0;
  vector<int> u(v.size());
  for (int i = 0; i < v.size(); i++) if (!u[i]) {
    int cyc = 1;
    u[i] = 1;
    for (int j = v[i]; j != i; j = v[j]) {
      cyc++;
      u[j] = 1;
    }
    ret += cyc-1;
  }
  return ret;
}*/

int seen[1001][1001];
main() {
  /*srand(time(0));
  for(int n = 0; n < 10000000; n++) {
    vector<int> v;
    for (int i = 0; i < 1000; i++) v.push_back(i);
    for (int i = 0; i < 1000; i++) {
      swap(v[i], v[rand()%(1000)]);
    }
    for (int i = 0; i < 1000; i++) seen[i][v[i]]++;
  }
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) cout << seen[i][j] << ' ';
    cout << endl;
  }
  exit(0);*/

  ifstream fin("C.txt");
  for (int i = 0; i < 1000; i++)
  for (int j = 0; j < 1000; j++)
    fin >> seen[i][j];

  int T, prob=1;
  for (cin >> T; T--;) {
    cout << "Case #" << prob++ << ": ";
    int N;
    cin >> N;
    double prob = 0.0;
    for (int i = 0; i < 1000; i++) {
      int x;
      cin >> x;
      prob += log(seen[i][x]);
    }
    if (prob > 9210.0) cout << "BAD"; else cout << "GOOD";
    cout << endl;
  }
}

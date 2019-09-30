#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<double> v;
  int tmp;
  for (int i=0; i<N; i++) {
    cin >> tmp;
    if (tmp != 0) v.push_back(tmp);
  }
  double res = accumulate(v.begin(), v.end(), 0);

  cout << ceil(res/(int)v.size()) << endl;
  //cout << (int)ceil/(int)v.size()) << endl;
}
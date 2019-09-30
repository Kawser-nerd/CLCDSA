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
  cin >>n;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  sort(v.begin(), v.end(), greater<int>());
  v.erase(unique(v.begin(), v.end()), v.end());
  cout << v[1] << endl;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  int N;

  cin >> N;

  int M = N;
  M %= 30;

  for(int i = 1; i <= 6; ++i) {
    v.emplace_back(((i+M/5)-1)%6 + 1);
  }

  M %= 5;
  int first = v[0];
  v.erase(v.begin());
  v.insert(v.begin()+M, first);

  for(auto card : v) {
    cout << card;
  }
  cout << endl;
}
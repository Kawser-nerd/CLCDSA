#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> list(N, 0);
  for (int i = 0; i < list.size(); i++) {
    cin >> list[i];
  }
  sort(list.begin(), list.end(), greater<int>());
  int max = list[0];
  for (int i = 0; i < list.size(); i++) {
    if (list[i] != max) {
      cout << list[i] << endl;
      break;
    }
  }
}
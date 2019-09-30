#include <iostream>
using namespace std;

int main() {
  int group[] = {0, 1, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0};
  int a, b;
  cin >> a >> b;
  cout << (group[a-1] == group[b-1] ? "Yes" : "No") << endl;
}
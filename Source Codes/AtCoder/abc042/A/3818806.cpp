#include <iostream>
using namespace std;

int main() {
  int abc[3];
  for (int i = 0; i < 3; i++)
    cin >> abc[i];
  sort(abc, abc + 3);

  if (abc[0] == 5 && abc[1] == 5 && abc[2] == 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
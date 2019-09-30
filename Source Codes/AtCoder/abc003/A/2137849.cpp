#include <iostream>
using namespace std;
#define print(var) cout << var << endl
int main() {
  int N;
  double res = 0;
  cin >> N;
  for (int i = 1; i <= N; i++)
    res += i;
  res *= 10000;
  res /= N;
  print(res);
}
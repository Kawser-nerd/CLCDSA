#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int a, b;
  char op;
  cin >> a >> op >> b;
  if (op == '+') cout << a + b << endl;
  else           cout << a - b << endl;
}
#include <iostream>
using namespace std;

int main()
{
char h = 0;
cin >> h;
switch (h)
{
  case 'A' : cout << "T";
    break;
  case 'T' : cout << "A";
    break;
  case 'G' : cout << "C";
    break;
  case 'C' : cout << "G";
    break;
  default:
    break;
}
}
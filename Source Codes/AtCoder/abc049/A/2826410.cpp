#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  char c;
  cin >> c;
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cout << "vowel" << endl;
  else cout << "consonant" << endl;
}
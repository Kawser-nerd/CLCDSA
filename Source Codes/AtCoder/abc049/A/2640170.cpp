#include <iostream>
#include <string>
using namespace std;

int main()
{
  string v = "aeiou", c;
  cin >> c;

  cout << ( v.find( c ) != string::npos ? "vowel" : "consonant" ) << endl;

  return 0;
}
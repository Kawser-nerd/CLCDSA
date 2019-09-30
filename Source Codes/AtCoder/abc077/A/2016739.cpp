#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  reverse(s1.begin(), s1.end());
  cout << (s1 == s2 ? "YES" : "NO") << endl;
  return 0;
}
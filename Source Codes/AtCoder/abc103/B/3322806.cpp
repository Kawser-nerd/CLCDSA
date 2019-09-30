#include <iostream>
using namespace std;

int main()
{
  string s, t;

  cin >> s >> t;
  s += s;
  cout << (s.find(t) != string::npos ? "Yes" : "No") << endl;
}
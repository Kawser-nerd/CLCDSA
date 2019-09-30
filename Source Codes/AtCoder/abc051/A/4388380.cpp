#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;
  s[5]=s[13]=' ';
  cout << s;
  return 0;
}
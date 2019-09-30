#include <iostream>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if(b-a==c-b)cout << "YES";
  else cout << "NO";
  return 0;
}
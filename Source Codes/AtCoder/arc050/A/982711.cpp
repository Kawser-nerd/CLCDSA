#include <iostream>

using namespace std;

int main(){
  char a,b;
  cin >> a >> b;
  if(a - b == 'A' - 'a')
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;

}
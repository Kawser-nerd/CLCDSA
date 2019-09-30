#include <iostream>
#include <string>
using namespace std;

int main(){
  string n;
  cin >> n;
  if(n[0]==n[2])cout << "Yes";
  else cout << "No";
  return 0;
}
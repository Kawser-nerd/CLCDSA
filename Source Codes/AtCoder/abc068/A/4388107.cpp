#include <iostream>
#include <string>
using namespace std;

int main(){
  int n;
  cin >> n;
  string str="";
  for(int i=0; i<3; i++){
    str.insert(str.begin(), n%10+'0');
    n/=10;
  }
  cout << "ABC" << str;
  return 0;
}
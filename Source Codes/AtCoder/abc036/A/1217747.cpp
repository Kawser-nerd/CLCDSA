#include<iostream>

using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
    if(B%A == 0)
      cout << B/A << endl;
    else
      cout << B/A + 1 << endl;
  return 0;
}
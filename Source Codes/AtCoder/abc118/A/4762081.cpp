#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
  int A, B;
  cin >> A >> B;
  if (B % A == 0){
    cout << A + B << endl;
  }else{
    cout << B - A << endl;
  }

  return 0;
}
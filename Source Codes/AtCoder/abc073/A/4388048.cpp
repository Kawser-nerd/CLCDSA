#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n%10==9 || n>=90)cout << "Yes";
  else cout << "No";
  return 0;
}
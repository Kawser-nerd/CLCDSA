#include <iostream>
using namespace std;
int main(){
  long long a,b,c;
  cin >> a >> b >> c;
  cout << min(b+c,a+2*b+1) << endl;
}
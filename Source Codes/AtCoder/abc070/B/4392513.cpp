#include <iostream>
using namespace std;

int main(){
  double a, b, c, d, ret=0;
  cin >> a >> b >> c >> d;
  for(double i=0.5; i<=100; i+=1){
    if(a<=i && i<=b && c<=i && i<=d)ret++;
  }
  cout << ret;
  return 0;
}
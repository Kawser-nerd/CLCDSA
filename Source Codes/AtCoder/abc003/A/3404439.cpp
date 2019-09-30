#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  double sum = 0;
  for(int i=0; i<n; i++){
    sum += (i+1) * 10000;
  }
  cout << sum / n << endl;
  return 0;
}
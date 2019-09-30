#include <iostream>
using namespace std;

int main(){
  int n, p=1;
  cin >> n;
  for(int i=0; i<8; i++){
    if(n<p){
      cout << p/2;
      return 0;
    }
    else if(n==p){
      cout << p;
      return 0;
    }
    p*=2;
  }
  return 0;
}
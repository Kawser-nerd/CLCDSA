#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int n;
  
  cin >> n;
  int p = 100;
  int a[3];
  
  for(int i = 0; i < 3; i++){
    a[i] = n / p;
    n %= p;
    p /= 10;
    
  }
  
  for(int i = 0; i < 3; i++){
    if(a[i] == 1){
      a[i] = 9;
      cout << a[i];
    } else if(a[i] == 9){
      a[i] = 1;
      cout << a[i];
    }
  }
  
  cout << endl;

  return 0;
}
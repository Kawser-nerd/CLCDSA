#include <iostream>
using namespace std;

int main(){
  int a, b;
  cin >> a;
  cin >> b;
  
  if((a * b) % 2 == 0){
  	cout << "Even" << endl;
  }else{
  	cout << "Odd" << endl;
  }
  
  return 0;
}
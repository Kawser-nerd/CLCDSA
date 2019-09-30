#include<iostream>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  
  int c = a * b;
  if(0 == c % 2){
    cout << "Even" << endl;
  }else{
    cout << "Odd" << endl;
  }
}
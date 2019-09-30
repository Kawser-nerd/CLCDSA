#include<iostream>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  
  int c = a * b;
  if(1 == c % 2){
    cout << "Odd" << endl;
  }else{
    cout << "Even" << endl;
  }
}
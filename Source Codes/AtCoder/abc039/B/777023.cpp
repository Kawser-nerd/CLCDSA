#include<iostream>
using namespace std;

int main(){
  int i;
  int X;

  cin >> X;

  for(i=0;i<X;i++){
    if(i*i*i*i == X) break;
  }

  cout << i << endl;

  return 0;
}
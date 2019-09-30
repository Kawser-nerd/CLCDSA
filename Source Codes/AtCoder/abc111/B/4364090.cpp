#include <iostream>
using namespace std;

int main(){
  int count, i;
  cin >> count;
  
  for(i=1;i<=9;i++){
	if(count <= i*111){
      break;
    }
  }
  cout << i*111;
}
#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b;
  char N;
  cin >>a;
  cin >> N;
  cin >> b;
  if(N=='+'){
	
  	cout << a+b<<endl;
  }else{
	cout << a-b<<endl;
  }
    return 0;
}
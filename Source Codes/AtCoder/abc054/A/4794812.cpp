#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c,d;
  cin >> a;
  cin >> b;
  if(a==b){
    cout <<"Draw" <<endl; 
    return 0;
  }
  
  if(a==1){
 	cout <<"Alice" <<endl; 
    return 0;
  }
  if(b==1) {
    cout <<"Bob" <<endl; 
    return 0;
  }
  if(a>b){
	
  	cout << "Alice"<<endl;
  }else{
	cout << "Bob"<<endl;
  }
    return 0;
}
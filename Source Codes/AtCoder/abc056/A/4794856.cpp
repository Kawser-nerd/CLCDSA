#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  char a,b,c,d;
  cin >> a;
  cin >> b;
  int s=0;
  if(a=='D')  s++;
  if(b=='D')  s++;
  
  if(s==1){
    cout << "D"<<endl;
  }else{
	cout << "H"<<endl;
  }
  
  
    return 0;
}
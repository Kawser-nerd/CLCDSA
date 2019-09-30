#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c,d;
  cin >> a;
  cin >>b;
  c=0;
  d=0;
  if(a==2||b==2) {
	cout <<"No" <<endl;
    return 0;
  }
  if(a==4||a==6||a==9||a==11) c=1;
  if(b==4||b==6||b==9||b==11) d=1;
  if(c==d){
	cout <<"Yes" <<endl;
  }else{
	cout <<"No" <<endl;
    
  }
    return 0;
}
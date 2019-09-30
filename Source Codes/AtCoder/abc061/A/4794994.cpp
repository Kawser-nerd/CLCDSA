#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c,d;
  cin >> a;
  cin >>b;
  cin >>c;
  if(a<=c&&c<=b){
	cout <<"Yes" <<endl;
  }else{
	cout << "No" <<endl;
  }
    return 0;
}
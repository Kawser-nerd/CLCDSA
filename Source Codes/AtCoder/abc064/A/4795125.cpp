#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c,d;
  cin >> a;
  cin >>b;
  cin >>c;
  if((b*10+c)%4==0){
	cout <<"YES" <<endl;
  }else{
	cout << "NO" <<endl;
  }
    return 0;
}
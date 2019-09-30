#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c,d;
  cin >> c;
  cin >>a;
  cin >>b;
  if(a-b>=0){
	cout <<"delicious" <<endl;
  }else if(b-a<=c){
	cout << "safe" <<endl;
  }else{
    cout <<"dangerous" <<endl;
  }
    return 0;
}
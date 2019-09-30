#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c,d;
  cin >> a;
  cin >>b;
  cin >>c;
  cin >>d;
  
  if(a+b>c+d){
    cout << "Left" << endl;
  }else if(a+b==c+d){
    cout << "Balanced" << endl;
  }else{
    cout << "Right" << endl;
  }
  
   return 0;
}
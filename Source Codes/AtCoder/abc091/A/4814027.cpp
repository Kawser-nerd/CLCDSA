#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c;
  cin >> a;
  cin >>b;
  cin >>c;
  
  if(a+b>=c){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
   return 0;
}
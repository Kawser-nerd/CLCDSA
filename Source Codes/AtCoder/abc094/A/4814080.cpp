#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c;
  cin >> a;
  cin >>b;
  cin >> c;
  
  
  if(c>=a && a+b>=c){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  
   return 0;
}
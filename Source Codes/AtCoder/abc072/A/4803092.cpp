#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b;
  cin >> a;
  cin >>b;
  
  if(a-b<0){
    cout << 0 << endl;
  }else{
    cout << a-b << endl;
  }
  
   return 0;
}
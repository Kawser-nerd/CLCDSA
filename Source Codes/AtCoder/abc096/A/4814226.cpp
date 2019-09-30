#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b;
  cin >> a;
  cin >>b;
  
  if(a<=b){
    cout << a << endl;
  }else{
    cout << a-1 << endl;
  }
  
   return 0;
}
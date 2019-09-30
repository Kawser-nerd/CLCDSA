#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  string a;
  cin >> a;
  
  if(a[0]==a[2]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
   return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  string a;
  cin >>a;
  sort(a.begin(),a.end());
  if(a=="abc"){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
   return 0;
}
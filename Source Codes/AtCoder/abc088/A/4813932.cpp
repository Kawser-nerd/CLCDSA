#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b;
  cin >> a;
  cin >>b;
  
  if(a%500<=b){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
   return 0;
}
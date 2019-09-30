#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c,d;
  cin >> a;
  cin >>b;
  cin >>c;
  cin >>d;
  
  
  if(abs(a-c)<=d){
    cout << "Yes" << endl;
  }else if(abs(a-b)<=d&&abs(b-c)<=d){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
   return 0;
}
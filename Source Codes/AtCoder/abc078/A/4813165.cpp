#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  char a,b;
  cin >> a;
  cin >>b;
  
  if(a>b){
    cout << ">" << endl;
  }else if(a==b){
    cout << "=" << endl;
  }else{
    cout << "<" << endl;
  }
  
   return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  string a,b;
  cin >> a;
  cin >>b;
  
  reverse(b.begin(),b.end());
  if(a==b){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  
   return 0;
}
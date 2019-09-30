#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b;
  cin >> a;
  cin >>b;
  
  if(a*b%3==0){
    cout << "Possible" << endl;
  }else if((a+b)%3==0){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
  
   return 0;
}
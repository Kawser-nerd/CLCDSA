#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c;
  cin >> a;
  cin >> b;
  
  
  if(a*b%2==0){
    cout << "No" <<endl;
  }else{
	cout << "Yes" <<endl;
  }
  
   return 0;
}
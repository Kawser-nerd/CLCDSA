#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c;
  cin >> a;
  
  if(a%2==0){
    cout << a*a/4 <<endl;
  }else{
	cout << (a+1)/2*(a-1)/2<<endl;
  }
  
   return 0;
}
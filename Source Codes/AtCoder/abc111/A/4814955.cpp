#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  string a,b,c;
  cin >> a;
  
  for(int i=0;i<3;i++){

  if(a[i]=='1'){
    a[i]='9';
  }else if(a[i]=='9'){
	a[i]='1';
  }
  }
  
    cout <<a <<endl;
   return 0;
}
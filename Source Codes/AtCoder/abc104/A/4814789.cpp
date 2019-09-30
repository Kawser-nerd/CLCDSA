#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c;
  cin >> a;
  
  if(a<1200){
    cout << "ABC" <<endl;
  }else if(a<2800){
	cout << "ARC" <<endl;
  }else{
	cout <<"AGC" <<endl;
  }
  
   return 0;
}
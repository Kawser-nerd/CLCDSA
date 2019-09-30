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
  if(a>b){
    c=a;
    a=b;
    b=c;
  }
  
  if(a*2+2*(b-a)>16){
    cout << ":(" <<endl;
  }else{
	cout << "Yay!" <<endl;
  }
  
   return 0;
}
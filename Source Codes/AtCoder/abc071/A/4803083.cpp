#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c;
  cin >> c;
  cin >>a;
  cin >>b;
  
  if(abs(c-a)<abs(c-b)){
    cout << "A" <<endl;
  }else{
	cout << "B" <<endl;
  }
   return 0;
}
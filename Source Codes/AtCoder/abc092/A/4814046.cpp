#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c,d;
  cin >> a;
  cin >>b;
  cin >>c;
  cin >>d;
  
  if(a>b)a=b;
  if(c>d)c=d;
  
  cout << a+c <<endl;
   return 0;
}
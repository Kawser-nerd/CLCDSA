#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b;
  vector<int> c(3);
  cin >> a;
  cin >>b;
  c[0]=a+b;
  c[1]=a-b;
  c[2]=a*b;
  sort(c.begin(),c.end());
  cout << c[2] <<endl;
  
   return 0;
}
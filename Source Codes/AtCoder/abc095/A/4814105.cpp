#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  string a;
  int b=0;
  cin >> a;
  
  
  if(a[0]=='o')b+=1;
  if(a[1]=='o')b+=1;
  if(a[2]=='o')b+=1;
  
  cout << (7+b)*100 <<endl;  
   return 0;
}
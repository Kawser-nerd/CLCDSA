#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  char a,b,c;
  cin >> a;
  
  if(a=='A') b='T';
   if(a=='T') b='A';
   if(a=='G') b='C';
   if(a=='C') b='G';
  
  cout <<b <<endl;
   return 0;
}
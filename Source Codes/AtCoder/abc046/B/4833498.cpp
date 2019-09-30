#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
	
  
  ll a,b,c,d,i,j,k;
  cin >> a;
  cin >> b;
  
  cout << int(b*pow(b-1,a-1)) <<endl;
  return 0;
}
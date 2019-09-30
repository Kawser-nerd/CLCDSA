#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
	
  
  int a,b,c,d,i,j,k;
  cin >> a;
  cin >> b;
  vector<string> s(a);
  
  for(i=0;i<a;i++){
	cin >>s[i];
  }
  sort(s.begin(),s.end());
  
  for(auto it=s.begin();it != s.end();it++){
	cout << *it ;
  }
  
  cout <<endl;
  
  return 0;
}
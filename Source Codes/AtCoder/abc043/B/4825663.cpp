#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
	
  string s;
  string t;
  int a,b,c,d,i,j,k;
  cin >> s;
  
  for(i=0; i < s.length() ; i++){
	if(s[i]=='1') t+='1';
    if(s[i]=='0') t+='0';
    if(s[i]=='B'&&t.length()>=1) t.pop_back();
  }
  
  cout << t <<endl;
  
  return 0;
}
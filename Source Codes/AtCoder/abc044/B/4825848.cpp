#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
	
  string s;
  int a,b,c,d,i,j,k;
  cin >> s;
  vector<int> l(26);
  
  for(i=0; i < s.length() ; i++){
    l[int(s[i]-'a')]++;
  }
  a=0;
  while(a<26){
	if(l[a]%2!=0){
		cout << "No" <<endl;
      return 0;
    }
    a++;
  }
  
  cout << "Yes" <<endl;
  
  return 0;
}
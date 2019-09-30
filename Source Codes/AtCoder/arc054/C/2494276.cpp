#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  bool even;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  for(int i=0;i<n;i++){
    even = true;
    for(int j=i;j<n;j++){
    	if(s[j][i]=='1'){ swap(s[i],s[j]); even = false; break;}
    }
    if(even) break;
    for(int j=i+1;j<n;j++){
      if(s[j][i] == '1'){
      	for(int k=i;k<n;k++) s[j][k] = (s[j][k] == '0')^(s[i][k] == '0') ? '1' : '0';
      }
    }
  }
 // for(int i=0;i<n;i++)cout << s[i] << endl;

  if(even) cout << "Even" << endl;
  else cout << "Odd" << endl;
  return 0;
}
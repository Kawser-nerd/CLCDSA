#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = (int)s.length();
  int ary[n];
  for(int i=0;i<n-2;++i) ary[i]=stoi(s.substr(i,3));
//  for(int i=0;i<n-2;++i) cout << ary[i] << endl;
  int ans=753;
  for(int i=0;i<n-2;++i){
    if(ans > abs(753-ary[i])) ans = abs(753-ary[i]);
  }
  
  cout << ans << endl;

  return 0;
}
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
typedef long long ll;
using namespace std;

int main(){
  string s;
  cin >> s;
  ll ans = 0;

  for(int t=0; t<(1<<(s.size()-1)); t++){
    ll num = s[0] -'0';
    for(int i=0; i<s.size()-1; i++){
      if(t&(1<<i)){
          ans+=num;
          num=0;
      }
      num=num*10+s[i+1]-'0';
    }
    ans+=num;
  }
  cout << ans << endl;
  return 0;
}
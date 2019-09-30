#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

#define all(c) (c).begin(),(c).end()

using namespace std;

int main(void){

  string s;
  cin >> s;

  long long cnt = 0;

  for(int i=0;i<s.size();i++){
    cnt += s[i]=='U' ? s.size()-i-1 : i;
    cnt += s[i]=='U' ? i*2 : (s.size()-i-1) * 2;
  }
  cout << cnt << endl;
  
  return 0;
}
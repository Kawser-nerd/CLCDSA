#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str;
long long cnt[216000];
int main(){
  cin >> str;
  for(int i = 0;i < str.size();i++)cnt[str[i]]++;

  long long res = str.size();
  res = res * (res + 1) / 2;
  for(int i = 'a';i <= 'z';i++){
    res -= cnt[i] * (cnt[i] + 1) / 2;
  }
  cout << res + 1 << endl;

  return 0;
}
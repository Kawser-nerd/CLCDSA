#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string S;
  cin >> S;

  vector<int> cnt(2, 0);  //??2???????????0???

  for (int i = 0; i < S.size(); i++){
  if (S[i] == '0') cnt[0]++;
  else cnt[1]++;
  }
  int ans = min(cnt[0], cnt[1]) * 2;

  cout << ans << endl;
}
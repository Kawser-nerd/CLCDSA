#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;



int main()
{
  int ans[26] = {};
  int n,i,j;  cin >> n;
  string s;
  cin >> s;
  for(i=0;i<s.length();i++){
    int tmp = char(s[i]) - 'a';
    ans[tmp]++;
  }

  for(i=1;i<n;i++){
    int tmp[26] = {};
    cin >> s;
    for(j=0;j<s.length();j++){
      int t = char(s[j]) - 'a';
      tmp[t]++;
    }
    for(j=0;j<26;j++)
      ans[j] = min(ans[j],tmp[j]);
  }
  int res = 0;
  for(i=0;i<26;i++)
    for(j=0;j<ans[i];j++)
      cout << char('a' + i) ;

  cout << endl;

  return 0;
}
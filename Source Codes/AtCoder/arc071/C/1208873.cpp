#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define MOD 1000000007
typedef long long Int;

string sstr, tstr;
vector<int> s, t;
Int a, b, c, d, q;
int main(){
  cin >> sstr;
  cin >> tstr;
  s.push_back(0);
  t.push_back(0);
  for(int i = 0;i < sstr.size();i++){
    if(sstr[i] == 'A')s.push_back(1);
    else s.push_back(2);
    s[i+1] += s[i];
    s[i+1] %= 3;

  }

  for(int i = 0;i < tstr.size();i++){
    if(tstr[i] == 'A')t.push_back(1);
    else t.push_back(2);
    t[i + 1] += t[i];
    t[i+1] %= 3;

  }
  
  cin >> q;
  for(int i = 0;i < q;i++){
    cin >> a >> b >> c >> d;
   
    if((s[b] - s[a-1] - t[d] + t[c-1])%3==0)cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;  
}
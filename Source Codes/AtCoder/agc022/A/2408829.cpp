#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  if(s.length() != 26){
    for(char ch = 'a'; ch <= 'z'; ch++){
      bool contains = false;
      for(int i = 0; i < s.length(); i++){
        if(s[i] == ch){
          contains = true;
          break;
        }
      }
      if(!contains){
        s.push_back(ch);
        cout << s << endl;
        return 0;
      }
    }
  }
  else{
    for(int i = s.length() - 1; i >= 0; i--){
      for(char ch = 'a'; ch <= 'z'; ch++){
        bool contains = false;
        for(int j = 0; j <= i; j++){
          if(s[j] == ch){
            contains = true;
            break;
          }
        }
        if(!contains && s[i] < ch){
          string ans = s.substr(0, i);
          ans.push_back(ch);
          cout << ans << endl;
          return 0;
        }
      }
    }
  }

  cout << -1 << endl;

  return 0;
}
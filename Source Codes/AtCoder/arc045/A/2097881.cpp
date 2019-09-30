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

vector< string > split(string s, char delimeter){
  vector< string > result;
  string tmp = "";
  for(char ch: s){
    if(ch == delimeter){
      result.push_back(tmp);
      tmp = "";
    }
    else{
      tmp.push_back(ch);
    }
  }
  result.push_back(tmp);
  return result;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string line;
  getline(cin, line);
  string ans;
  for(string s: split(line, ' ')){
    if(s == "Left"){
      ans += "<";
    }
    else if(s == "Right"){
      ans += ">";
    }
    else{
      ans += "A";
    }
    ans += " ";
  }
  ans.erase(ans.length() - 1);

  cout << ans << endl;

  return 0;
}
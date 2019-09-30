#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define v_exists(elem, v) find(v.begin(),v.end(),elem)!=v.end()

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<string> ws;

  rep(i,n){
    string w;
    cin >> w;

    if(i != 0 && (v_exists(w, ws) == true || ws[i-1].at(ws[i-1].length()-1)!=w.at(0))){
      cout << "No" << endl;
      return 0;
    }

    ws.push_back(w);
  }

  cout << "Yes" << endl;
  return 0;
}
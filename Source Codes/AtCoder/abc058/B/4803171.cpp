#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<utility>
#include<vector>
#include<map>
#include<functional>
#include<math.h>
#include<algorithm>
typedef long long ll;
using namespace std;

int main(){
  string o,e;
  cin >> o;
  cin >> e;
  bool loop = o.size() > e.size();
  string miria = "";
  for(int i=0;i<e.size();i++){
    cout << o[i] << e[i];
  }
  if(loop){
    cout << o[e.size()] << endl;
  }else{
    cout << endl;
  }
  return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;
#define ll long long int

bool solve(string s){
  if(s > "2019/04/30")return true;
  else return false;

}

void output(bool ok){
  if(ok)cout<<"TBD"<<endl;
  else cout<<"Heisei"<<endl;  
}

int main(){ 
  string s;
  cin >> s;
  bool ok = solve(s);
  output(ok);
  return 0;
}
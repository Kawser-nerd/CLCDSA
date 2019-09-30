#include<iostream>
using namespace std;

void a(){
  string s;

  cin >> s;

  for(int i=0; i<(int)s.size(); i++){
    if('0'<=s[i] && s[i]<='9') cout << s[i];
  }
  cout << endl;
}

int main(){
  a();
}
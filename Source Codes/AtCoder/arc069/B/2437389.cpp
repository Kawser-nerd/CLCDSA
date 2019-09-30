#include <iostream>
#include <string>
using namespace std;


char ca(char cc){
  	if(cc=='S') return 'W';
    else return 'S';
}

int main(){
  int n;
  string c;
  cin >> n;
  cin >> c;
  string s(n,'S');
  bool flag=false;
  for(int i=0;i<4;i++){
    //SS...
    if(i==0){
      s[0]='S'; s[1] = 'S';
    }
    //SW...
    if(i==1){
      s[0]='S'; s[1] = 'W';
    }
    //WS...
    if(i==2){
      s[0]='W'; s[1] = 'S';
    }
    //WW...
    if(i==3){
      s[0]='W'; s[1] = 'W';
    }
    for(int j=2;j<n;j++){
    	s[j] = (s[j-1]=='S')==(c[j-1]=='o') ? s[j-2] : ca(s[j-2]);
    }
    if(s[0] == ((s[n-1]=='S')==(c[n-1]=='o') ? s[n-2] : ca(s[n-2]))
      &&
       s[n-1] == ((s[0]=='S')==(c[0]=='o') ? s[1] : ca(s[1]))
      ){
    	flag = true;
      	break;
    } 
  }
  if(flag) cout << s << endl;
  else cout << "-1" << endl;
}
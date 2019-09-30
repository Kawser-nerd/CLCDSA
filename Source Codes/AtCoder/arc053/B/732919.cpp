#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <map>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define MAX_N 105
int vx [4]= {1,0,-1,0};
int vy [4]= {0,1,0,-1};
using namespace std;
int al[26]={};
void init(){
  string s ;
  cin >> s;
  int p=0,m=0;
  char c;
  REP(i,s.length()){
    c = s[i];
    al[(int)(c-'a')]++;
  }
  REP(i,26){
    p +=al[i]/2;
    m +=al[i]%2;
  }
  if(m>p){
    cout << 1<<endl;
  }else if(m==0||m==1){
    cout << s.length();
  }else{
    int t = p-m;
    int now =3;
    while(t>=m){
        now +=2;
        t=t-m;
        //cout << now <<'_'<<t<<endl;
    }
    cout <<now<<endl;
  }
}
void solve(){
}
int main(){
  init();

}
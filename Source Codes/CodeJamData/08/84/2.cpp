#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

#define MOD 30031
#define MAX 500
int m[MAX][MAX],t[MAX][MAX],r[MAX][MAX],D,N,K,P;
void mult(int a[MAX][MAX],int b[MAX][MAX],int c[MAX][MAX]){
  FOR(i,D)FOR(j,D){
    int64 s=0;
    FOR(k,D)s+=a[i][k]*b[k][j];
    r[i][j]=s%MOD; 
  }
  FOR(i,D)FOR(j,D)c[i][j]=r[i][j];
}

map<string,int> name;
int next_name;
int conv(string x){
  if(name.count(x))return name[x];
  if(next_name+2==MAX)throw 0xdead;
  return name[x]=next_name++;
}
void add(string x,string y){
//  cout<<x<<" -> "<<y<<endl;
  m[conv(x)][conv(y)]++;
//  cout<<conv(x)<<" "<<conv(y)<<endl;
}
main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){
    cin>>N>>K>>P;
    memset(m,0,sizeof(m));
    name.clear();next_name=0;
    P++;
    FOR(i,1<<P){
      int cnt=0;FOR(j,P)if(i&1<<j)cnt++;
      if(cnt!=K)continue;      
      string s="";
      FOR(j,P)s+=(i&1<<j)?"*":".";
      if(s[0]=='.')continue;
      s+='.';
      FOR(j,P)if(s[j]=='.'){
         string s2=s;
         s2[j]='*';
         add(s.substr(0,s.size()-1),s2.substr(1));
         s2[j]='.';         
      }
    }
    cout<<"Case #"<<c<<": ";
    if(N<K){cout<<0<<endl;continue;}
    N-=K;
    string _start;FOR(i,K)_start+='*';FOR(i,P-K)_start+='.';
    int start=conv(_start);
//    cout<<"start="<<start<<endl;
    D=next_name;
    memset(t,0,sizeof(t));
    FOR(i,D)t[i][i]=1;
    while(N){
      if(N&1){
//    cout<<endl<<endl<<endl<<"m="<<endl;      
//      FOR(i,D){FOR(j,D)cout<<m[i][j]<<" ";cout<<endl;}
 
 
        mult(m,t,t);
//    cout<<endl<<endl<<"t="<<endl;
//      FOR(i,D){FOR(j,D)cout<<t[i][j]<<" ";cout<<endl;}
//      cout<<"ans="<<t[start][start]<<endl;
        
}
      mult(m,m,m);
      N>>=1; 
    }
    cout<<t[start][start]<<endl;
  }
}

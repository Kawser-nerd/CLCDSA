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

int64 calc(vi t){
  int64 ans=0,cur=t[0];  
  FOR(i,t.size()){
    ans+=cur<?=t[i];
  }
  return ans;
}
int64 calc2(vi t){
  int64 ans=0,cur=t[0];  
  FOR(i,t.size()){
    ans+=cur>?=t[i];
  }
  return ans;
}
#define MAX 62000
int min_x[MAX],max_x[MAX];
main(){
  int L,C;cin>>C;
  for(int c=1;c<=C;c++){
    cin>>L;
    int x=31000,y=31000,dir=0,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1}; 
    FOR(i,MAX){
      min_x[i]=MAX;
      max_x[i]=-1;
    }
    int64 area=0,whole=0;
    while(L--){
      string s;
      int cnt;      
      cin>>s>>cnt;
      while(cnt--)FOR(i,s.size())if(s[i]=='L')dir=(dir+1)%4;else if(s[i]=='R')dir=(dir+3)%4; else {
        switch(dir){
        case 1: min_x[y-1]<?=x;max_x[y-1]>?=x;area+=x;break;
        case 3: min_x[y]<?=x;max_x[y]>?=x;area-=x;break;
        }
        x+=dx[dir];
        y+=dy[dir];
      }
    }
    int left=*min_element(min_x,min_x+MAX),right=*max_element(max_x,max_x+MAX),pos;
    typedef pair<int,int> p2;
    vi t;

    pos=0;
    while(min_x[pos]==MAX)pos++;
    while(min_x[pos]>left)t.push_back(min_x[pos++]);
    t.push_back(left);
    whole-=calc(t);
    t.clear();
    while(min_x[pos]!=MAX)t.push_back(min_x[pos++]);
    reverse(t.begin(),t.end());
    whole-=calc(t);
    whole+=left;

    t.clear();
    pos=0;
    while(max_x[pos]==-1)pos++;
    while(max_x[pos]<right)t.push_back(max_x[pos++]);
    t.push_back(right);
    whole+=calc2(t);
    t.clear();
    while(max_x[pos]!=-1)t.push_back(max_x[pos++]);
    reverse(t.begin(),t.end());
    whole+=calc2(t);
    whole-=right;
    
    if(area<0)area=-area;
    cout<<"Case #"<<c<<": "<<whole-area<<endl;
  }
}

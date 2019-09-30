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

#define MAX 6000
int x[MAX],y[MAX],z[MAX],s[MAX];
main(){
  int C,n;cin>>C;
  for(int c=1;c<=C;c++){
    cin>>n;
    FOR(i,n)cin>>x[i]>>y[i]>>z[i],s[i]=10000-z[i];
    int m=0;  
    for(int cur_y=0;cur_y<=10000;cur_y++){
      typedef pair<int,int> p2;
      vector<p2> t;
      FOR(i,n)if(y[i]<=cur_y){
        // x[i] <=  s[i]-cur_y
        int from=x[i],to=s[i]-cur_y;
        if (from>to)continue;
        t.push_back(p2(from,1));
        t.push_back(p2(to+1,-1));
      }
      sort(t.begin(),t.end());
//      if(t.size()>2){cout<<cur_y<<":";FOR(i,t.size())cout<<t[i].first<<","<<t[i].second<<" ";cout<<endl;}
      int cur=0;
      FOR(i,t.size())m>?=cur+=t[i].second;
    }
    cout<<"Case #"<<c<<": "<<m<<endl;
  }
}

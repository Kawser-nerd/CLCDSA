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

int read(){
  int h,m;
  scanf(" %d:%d",&h,&m);
  return h*60+m;
}
main(){
  int c,t,a,b;
  scanf("%d",&c);
  for(int cc=1;cc<=c;cc++){
    scanf("%d %d %d",&t,&a,&b);
    vi start_a[24*60],start_b[24*60];
    int add_a[24*60+100]={},add_b[24*60+100]={},used_a=0,used_b=0,avail_a=0,avail_b=0;
    FOR(i,a){
      int x=read(),y=read();
      start_a[x].push_back(y);
    }
    FOR(i,b){
      int x=read(),y=read();
      start_b[x].push_back(y);
    }
    FOR(i,24*60){
      avail_a+=add_a[i];
      avail_b+=add_b[i];
      FOR(j,start_a[i].size()){
        if(avail_a)avail_a--;else used_a++;
        add_b[start_a[i][j]+t]++;
      }
      FOR(j,start_b[i].size()){
        if(avail_b)avail_b--;else used_b++;
        add_a[start_b[i][j]+t]++;
      }
    }
    printf("Case #%d: %d %d\n",cc,used_a,used_b);
  }
}

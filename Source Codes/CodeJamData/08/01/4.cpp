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

char buf[1000000];
main(){
  int c,s,q;
  gets(buf);
  sscanf(buf,"%d",&c);
  for(int cc=1;cc<=c;cc++){
    gets(buf);
    sscanf(buf,"%d",&s);
    map<string,int> nr;
    FOR(i,s)gets(buf),nr[buf]=i;
    gets(buf);
    sscanf(buf,"%d",&q);
    int m[1100];
    FOR(i,s)m[i]=0;
    FOR(i,q){
      gets(buf);
      int next=nr[buf],best=*min_element(m,m+s);
      FOR(j,s)m[j]<?=best+1;      
      m[next]=1000000;
    }
    printf("Case #%d: %d\n",cc,*min_element(m,m+s));
  }
}

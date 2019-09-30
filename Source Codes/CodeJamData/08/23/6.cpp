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
#include<deque>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

int t[1100000];
main(){
  int T;cin>>T;
  for(int c=1;c<=T;c++){
    int K,n,q[5010];
    cin>>K>>n;
    FOR(i,n)cin>>q[i];
    int pos=0,size=0;
    for(int i=K;i>=1;i--){
      t[i]=pos;
      size++;
      int m=i%size-1;
      pos=(pos+size-m)%size;
    }
    cout<<"Case #"<<c<<":";
    FOR(i,n){
      int nr=(pos+q[i]-1)%K;
      for(int i=1;i<=K;i++){
        if(nr==t[i]){cout<<" "<<i;break;}
        nr-=t[i]<nr;
      }
    }
    cout<<endl;
  }
}

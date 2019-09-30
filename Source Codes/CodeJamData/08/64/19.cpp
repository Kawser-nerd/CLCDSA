#include <iostream>
#include <sstream>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

void solve()
{
  int n;cin>>n;
  set<pair<int,int> > as;
  for (int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    a--,b--;
    as.insert(make_pair(a,b));
    as.insert(make_pair(b,a));
  }
  int m;cin>>m;
  vector<pair<int,int> > bs(m-1);
  for (int i=0;i<m-1;i++){
    cin>>bs[i].first>>bs[i].second;
    bs[i].first--;
    bs[i].second--;
  }

  vector<int> p(n);
  for (int i=0;i<n;i++) p[i]=i;

  bool ans=false;

  do{
    bool ok=true;
    for (int i=0;i<m-1;i++){
      if (as.count(make_pair(p[bs[i].first],p[bs[i].second]))==0){
	ok=false;
	break;
      }
    }
    if (ok){
      /*
      for (int i=0;i<n;i++)
	cout<<p[i]<<" ";
      cout<<endl;
      */
      ans=true;
    }
  }while(next_permutation(p.begin(),p.end()));

  cout<<(ans?"YES":"NO")<<endl;
}

int main()
{
  int cases;
  cin>>cases;
  for (int c=1;c<=cases;c++){
    cout<<"Case #"<<c<<": ";
    solve();
  }
  return 0;
}

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

  vector<pair<int,int> > yes;
  vector<pair<int,int> > no;

  for (int i=0;i<n;i++){
    int h,w;
    string t1,t2;
    cin>>h>>w>>t1;
    if (t1=="BIRD"){
      yes.push_back(make_pair(h,w));
    }
    else{
      cin>>t2;
      no.push_back(make_pair(h,w));
    }
  }

  int ihmin=1000001,ihmax=0;
  int iwmin=1000001,iwmax=0;
  for (int i=0;i<yes.size();i++){
    int h=yes[i].first;
    int w=yes[i].second;
    ihmin=min(ihmin,h);
    ihmax=max(ihmax,h);
    iwmin=min(iwmin,w);
    iwmax=max(iwmax,w);
  }

  int ohmin=0,ohmax=1000001;
  int owmin=0,owmax=1000001;

  if (ihmin<=ihmax){
    for (int i=0;i<no.size();i++){
      int h=no[i].first;
      int w=no[i].second;
      if (iwmin<=w&&w<=iwmax){
	if (h<=ihmin){
	  ohmin=max(ohmin,h);
	}
	else{
	  ohmax=min(ohmax,h);
	}
      }
    }
  }

  if (iwmin<=iwmax){
    for (int i=0;i<no.size();i++){
      int h=no[i].first;
      int w=no[i].second;
      if (ihmin<=h&&h<=ihmax){
	if (w<=iwmin){
	  owmin=max(owmin,w);
	}
	else{
	  owmax=min(owmax,w);
	}
      }
    }
  }

  int m;cin>>m;
  for (int i=0;i<m;i++){
    int h,w;
    cin>>h>>w;
    if (ihmin<=h&&h<=ihmax&&
	iwmin<=w&&w<=iwmax){
      cout<<"BIRD"<<endl;
    }
    else if (h<=ohmin||ohmax<=h||
	     w<=owmin||owmax<=w){
      cout<<"NOT BIRD"<<endl;
    }
    else{
      cout<<"UNKNOWN"<<endl;
    }
  }
}

int main()
{
  int cases;
  cin>>cases;
  for (int c=1;c<=cases;c++){
    cout<<"Case #"<<c<<":"<<endl;
    solve();
  }
  return 0;
}

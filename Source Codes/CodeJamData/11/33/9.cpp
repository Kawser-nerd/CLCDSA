#include <cstdio>
#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <algorithm>
#include <functional>
#include <fstream>
#include <numeric>
#include <string>
#include <valarray>
#define int long long 

using namespace std;

int MX=10000000000000001ll;

template<class t>
ostream & operator << (ostream & tout,const vector<t> &s){
  tout<<'[';
  for (int i=0;i<s.size();i++)
    if (i+1 == s.size())
      tout<<s[i];
    else
      tout<<s[i]<<',';
  tout<<']';
  return(tout);
}


int kmm(int s,int t){
  int p=__gcd(s,t);
  if (MX/t >= s/p)
    return((s/p)*t);
  else
    return(MX);
}

#undef int
int main(){
#define int long long
  int ttime;
  cin>>ttime;
  for (int ccount=1;ccount<=ttime;ccount++){
    cerr<<ccount<<endl;
    int n,l,h;
    vector<int> all;
    cin>>n>>l>>h;
    for (int i=1;i<=n;i++){
      int x;
      cin>>x;
      all.push_back(x);
    }
    sort(all.begin(),all.end());
    all.resize(unique(all.begin(),all.end())-all.begin());
    int result=-1;
//     cout<<all<<endl;
    for (int i=0;i<=all.size();i++){
      int x,y;
      if (i > 0)
	x=all[i-1];
      else
	x=l;
      if (i < all.size())
	y=all[i];
      else
	y=h;
      if (x < l)
	x=l;
      if (y > h)
	y=h;
      int a=1,b=1;
      if (i < all.size())
	b=all[i];
      for (int j=i;j<all.size();j++)
	b=__gcd(all[j],b);
      for (int j=0;j<i;j++)
	a=kmm(a,all[j]);
      if (i == all.size()){
	int t = ((x+a-1)/a)*a;
	if (t <= y)
	  result=t;
	break;
      }
      if (b % a)
	continue;
      int q=b/a,p=(x+a-1)/a;
      
      int rq=q+1;
      for (int j=1;j*j<=q;j++)
	if (q % j == 0){
	  if (j >= p)
	    rq<?=j;
	  if (q/j >= p)
	    rq<?=q/j;
	}
      if (rq <= q)
	rq*=a;
      else
	rq=h+1;
      if (rq <= y){
	result=rq;
	break;
      }
    }
    if (result == -1)
      cout<<"Case #"<<ccount<<": "<<"NO"<<endl;
    else
      cout<<"Case #"<<ccount<<": "<<result<<endl;
  }
}

#include <iostream>
#include <iomanip>
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

double rec(int m,int x,double p,vector<vector<double> > &tbl)
{
  if (m==0&&x>=1) return 1;
  if (m==0) return 0;

  double &ret=tbl[m][x];

  if (ret>=-0.5) return ret;

  ret=0;

  for (int i=0;i<=x;i++){
    double tmp=
      (rec(m-1,(x+i)/2,p,tbl)*p+
       rec(m-1,(x-i)/2,p,tbl)*(1-p));
    //cout<<tmp<<" "<<i<<endl;
    ret=max(ret,tmp);
  }

  return ret;
}

void solve()
{
  int m,x;
  double p;
  cin>>m>>p>>x;
  vector<vector<double> > tbl(m+1,vector<double>((1<<15)+1,-1));
  double unit=1000000;
  for (int i=0;i<m;i++) unit/=2;
  cout<<rec(m,(int)(x/unit),p,tbl)<<endl;
}

int main()
{
  cout<<setiosflags(ios::fixed)<<setprecision(10);
  int cases;
  cin>>cases;
  for (int c=1;c<=cases;c++){
    cout<<"Case #"<<c<<": ";
    solve();
  }
  return 0;
}

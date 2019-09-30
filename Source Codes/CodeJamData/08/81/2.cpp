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

double m[2][2],t[2];
main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){
    double x[3],y[3],xx[3],yy[3];
    FOR(i,3)cin>>x[i]>>y[i];
    FOR(i,3)cin>>xx[i]>>yy[i];
    typedef pair<double,double> p2;
    p2 origin=p2(x[0],y[0]),origin2=p2(xx[0],yy[0]);
    p2 a=p2(x[1]-x[0],y[1]-y[0]),b=p2(x[2]-x[0],y[2]-y[0]);
    p2 a2=p2(xx[1]-xx[0],yy[1]-yy[0]),b2=p2(xx[2]-xx[0],yy[2]-yy[0]);
    t[0]=origin2.first-origin.first;
    t[1]=origin2.second-origin.second;
    m[0][0]=a.first-a2.first;
    m[0][1]=b.first-b2.first;
    m[1][0]=a.second-a2.second;
    m[1][1]=b.second-b2.second;
//FOR(i,2){FOR(j,2)cout<<m[i][j]<<" ";cout<<":"<<t[i]<<endl;}  
    FOR(i,2){
      int j=i;
#define EPS (1e-7)
      while(j<2&&fabs(m[j][i])<EPS)j++;
      if(j==2)goto fail;
      FOR(k,2)swap(m[i][k],m[j][k]);
      swap(t[i],t[j]);
      double scale=m[i][i];
      FOR(k,2)m[i][k]/=scale;
      t[i]/=scale;
      FOR(j,2)if(i!=j){
        scale=m[j][i];
        FOR(k,2)m[j][k]-=scale*m[i][k];
        t[j]-=scale*t[i];
      }
    }
//FOR(i,2){FOR(j,2)cout<<m[i][j]<<" ";cout<<":"<<t[i]<<endl;}
    cout<<"Case #"<<c<<": ";
    double sx=origin.first+a.first*t[0]+b.first*t[1],sy=origin.second+a.second*t[0]+b.second*t[1];
    printf("%.6lf %.6lf\n",sx,sy);
    continue;
fail:
    cout<<"????"<<endl;
  }
}

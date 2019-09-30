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

double sqr(double x){return x*x;}
double cut(double R,double x){
  double y=sqrt(sqr(R)-sqr(x)>?1e-12),a=atan2(y,x);
  return a*sqr(R)-x*y;
}
double area_upper_right(double R,double x,double y){//x,y>=0
  if(sqr(x)+sqr(y)>sqr(R))return 0;
  double x_min=x,x_max=sqrt(sqr(R)-sqr(y)>?1e-12);
  if(x_min>x_max)return 0;
  return (cut(R,x_min)-cut(R,x_max))/2-(x_max-x_min)*y;
}
double area_upper(double R,double x,double y){//y>=0
  if(x>0)return area_upper_right(R,x,y);
  return 2*area_upper_right(R,0,y)-area_upper_right(R,-x,y);
}
double area(double R,double x,double y){
  if(y>0)return area_upper(R,x,y);
  return 2*area_upper(R,x,0)-area_upper(R,x,-y);
}
double area(double R,double x0,double x1,double y0,double y1){
  return area(R,x0,y0)-area(R,x0,y1)-area(R,x1,y0)+area(R,x1,y1);
}
double calc2(double R,double r,double g){
  typedef pair<double,double> p2;
  double from=-r,to=r;
  while(to>-R)from-=2*r+g,to-=2*r+g;
  vector<p2> t;
  while(from<R){
    t.push_back(p2(from,to));
    from+=2*r+g;
    to+=2*r+g;
  }
  double sum=0;
  FOR(i,t.size())sum+=2*area(R,t[i].first,t[i].second,-R,R);
  FOR(i,t.size())FOR(j,t.size())sum-=area(R,t[i].first,t[i].second,t[j].first,t[j].second);
  return sum/M_PI/sqr(R);
}
double calc(double f,double R,double r,double g){
  if(2*f>g)return 1;
  return calc2(R,r+f,g-2*f);
}
main(){
  int c;
  scanf("%d",&c);
  for(int cc=1;cc<=c;cc++){
    double f,R,t,r,g,ans=0;
    scanf("%lf %lf %lf %lf %lf",&f,&R,&t,&r,&g);
    double all=M_PI*sqr(R),inside=M_PI*sqr(R-t),outside=all-inside;
    if(f+t>R)ans=1;
    else ans=(calc(f,R-f-t,r,g)*sqr(R-f-t)+sqr(R)-sqr(R-f-t))/sqr(R);
    printf("Case #%d: %.6lf\n",cc,ans);
  }
}

#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<double,double> pii;

#define x   first
#define y   second

int n;

void Solve(){
    cin>>n;
    double x=0,y=0,z=0,vx=0,vy=0,vz=0;
    for(int i=0;i<n;++i){
        double X,Y,Z,a,b,c;
        cin>>X>>Y>>Z>>a>>b>>c;
        x+=X,y+=Y,z+=Z,vx+=a,vy+=b,vz+=c;
    }
    x/=n,y/=n,z/=n,vx/=n,vy/=n,vz/=n;
    double A=vx*vx+vy*vy+vz*vz,B=2*(vx*x+vy*y+vz*z),C=x*x+y*y+z*z;
    double res=sqrt(x*x+y*y+z*z),t=0;
    if(fabs(A)>1e-9){
        double D=B*B-4*A*C;
        if(D<0)D=0;
        D=sqrt(D);
        for(int k=0;k<2;++k){
            double T=(D-B)/(2*A);
            if(T>0){
                double X=x+vx*T,Y=y+vy*T,Z=z+vz*T;
                double DD=sqrt(X*X+Y*Y+Z*Z);
                if(DD<res)res=DD,t=T;
            }
            D=-D;
        }
    }
    printf("%.8lf %.8lf\n",res,t);
}

int main(){
    #ifdef LocalHost
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    #endif
    int a=0,b;
    for(cin>>b;a++<b;Solve())printf("Case #%d: ",a);
    return 0;
}

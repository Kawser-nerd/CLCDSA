#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    double ax,ay,bx,by,x[100],y[100],a,b,c,aa,bb,cc,xx,yy;
    int n,cnt=0;
    scanf("%lf %lf %lf %lf",&ax,&ay,&bx,&by);
    if(ax==bx){
        a=1;
        b=0;
        c=-ax;
    }
    else if(by==ay){
        a=0;
        b=1;
        c=-ay;
    }
    else{
        a=(ay-by);
        b=-(ax-bx);
        c=-a*ax-b*ay;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&x[i],&y[i]);
    }
    for(int i=0;i<n;i++){
        if(x[i]==x[(i+1)%n]){
            aa=1;
            bb=0;
            cc=-x[i];
        }
        else if(y[(i+1)%n]==y[i]){
            aa=0;
            bb=1;
            cc=-y[i];
        }
        else{
            aa=(y[i]-y[(i+1)%n]);
            bb=-(x[i]-x[(i+1)%n]);
            cc=-aa*x[i]-bb*y[i];
        }
        if(a*bb-aa*b){
            xx=(b*cc-bb*c)/(a*bb-aa*b);
            yy=(aa*c-a*cc)/(a*bb-aa*b);
            if(xx<=max(x[i],x[(i+1)%n])&&min(x[i],x[(i+1)%n])<=xx&&yy<=max(y[i],y[(i+1)%n])&&min(y[i],y[(i+1)%n])<=yy&&xx<=max(ax,bx)&&min(ax,bx)<=xx&&yy<=max(ay,by)&&min(ay,by)<=yy){
                cnt++;
            }
        }
    }
    printf("%d\n",1+cnt/2);
}
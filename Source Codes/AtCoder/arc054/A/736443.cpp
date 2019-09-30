#include <cstdio>

using namespace std;

int main(){
    int l,x,y,s,d;
    int rv,v;

    scanf("%d%d%d%d%d",&l,&x,&y,&s,&d);

    rv = y - x;
    v = y + x;

    
    double gr,g;
    if(s > d){
        g = (double)(l - s + d);
        gr = (double)(s - d);
    }
    else{
        g = (double)(d - s);
        gr = (double)(l - d + s);
    }
    if((g / (double)v > gr / (double)rv ) && rv >= 0){
        printf("%lf\n",gr / (double)rv);
    }
    else {
        printf("%lf\n",g / (double)v);
    }

    return 0;
}
#include <cstdio>
#include <cmath>

using namespace std;

double f(double x,double p){
    return (x + p/pow(2.0,x/1.5));
}

int main(){
    double p;
    double left,right;

    scanf("%lf",&p);

    left = 0;

    right = p;

    double rfx,lfx;

    for(int i=0;i<1000;i++){
        rfx = f((right - left) * (2.0 / 3.0) + left,p);
        lfx = f((right - left) / 3.0 + left,p);

        if(rfx > lfx)
            right = (right - left) * (2.0 / 3.0) + left;
        else 
            left = (right - left) / 3.0 + left;
    }

    //printf("left:%.10lf\nright:%.10lf\n",lfx,rfx);
    printf("%.10lf\n",lfx);

    return 0;
}
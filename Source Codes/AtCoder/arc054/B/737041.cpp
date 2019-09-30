#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    double p;

    scanf("%lf",&p);

    double oldt = 10e19,newt = p;

    double t=0;
    while(oldt > newt){
        oldt = newt;

        t += 0.00001;
        newt = t + (p/pow(2.0,t/1.5));

//        printf("%.10lf\n",newt);
        
    }

    printf("%.10lf\n",oldt);

    return 0;
}
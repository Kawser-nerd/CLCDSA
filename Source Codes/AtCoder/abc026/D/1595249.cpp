#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int A, B, C;

inline double f(double t){
    return A*t+B*sin(C*t*M_PI);
}

int main(){
    cin >> A >> B >> C;
    double lb = 0.0;
    double ub = 1e6;
    while(ub-lb>1e-12){
        double mid = 0.5*(lb+ub);
        if(f(mid)<100.0) lb=mid;
        else ub=mid;
    }
    cout << fixed << setprecision(12) << lb << endl;
    return 0;
}
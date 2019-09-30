#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double calc (double P, double c) {
    double t = c + (P / pow(2, c/1.5));
    return t;
}

int main()
{
    double P;
    cin >> P;
    
    double c = 0;
    double x = P;
    
    while (x > 100) {
        c += 1.5;
        x /= 2;
    }
    
    double min = c;
    double max = c + 100;
    double d = 100;
    
    for (int i=0; i<100; i++) {
        d /= 2;
        double t1 = calc(P, min + d);
        double t2 = calc(P, min + d + 0.000000001);
        if (t1 > t2) {
            min += d;
        } else {
            max -= d;
        }
    }

    cout << fixed << setprecision(10) << calc(P, min) << endl;
    
    return 0;
}
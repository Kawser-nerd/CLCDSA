#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double L, X, Y, S, D;
    cin >> L >> X >> Y >> S >> D;

    if (S < D) {
        // S??D???
        // 0 < S < D < L
        // D - S
        // L + S - D  reverse
        double v1 = Y + X;
        double t1 = (D - S) / v1;
        
        double v2 = Y - X;
        if (v2 > 0) {
            double t2 = (L + S - D) / v2;
            if (t2 < t1) {
                t1 = t2;
            }
        }
        
        cout << fixed << setprecision(10) << t1 << endl;;
    } else {
        // 0 < D < S < L
        // L + D - S
        // S - D reverse
        double v1 = Y + X;
        double t1 = (L + D - S) / v1;
        
        double v2 = Y - X;
        if (v2 > 0) {
            double t2 = (S - D) / v2;
            if (t2 < t1) {
                t1 = t2;
            }
        }
        
        cout << fixed << setprecision(10) << t1 << endl;;
    }
    
    return 0;
}
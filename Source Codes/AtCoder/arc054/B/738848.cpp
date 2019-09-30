#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <list>
#include <math.h>
#include <limits> 
#include <iomanip>      // std::setprecision
using namespace std;

int main()
{
    // get a integer
    double P;
    cin >> P;

    /* cout << P / pow( 2, 1.5 / 1.5 ) + 1.5 << endl;; */
    /* cout << P << endl; */

    double lower = 0.0;
    double upper = P;
    double curr_min = upper;
    double epsilon = 1.0 / 10000000000.0;
    int counter = 0;
    while( true )
    {
        double half = ( upper + lower ) / 2.0;
        double half0 = half - epsilon;
        double half1 = half + epsilon;
        double time0 = ( P / pow( 2, half0 / 1.5 ) ) + half0;
        double time1 = ( P / pow( 2, half1 / 1.5 ) ) + half1;

        if( time0 <= time1 )
        {
            upper = half;
            if( time0 < curr_min )
            {
                curr_min = time0;
            }
        }
        else
        {
            lower = half;
            if( time1 < curr_min )
            {
                curr_min = time0;
            }
        }

        if( counter > 100 )
        {
            break;
        }
        counter++;
    }
    cout << fixed << setprecision(10) << curr_min << endl;
}
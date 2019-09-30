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
    int L, X, Y, S, D;
    cin >> L >> X >> Y >> S >> D;

    double time0, time1, time2, time3;
    time0 = std::numeric_limits<double>::max();
    time1 = std::numeric_limits<double>::max();
    time2 = std::numeric_limits<double>::max();
    time3 = std::numeric_limits<double>::max();

    if( D > S )
    {
        // plus
        double dist = D - S;
        double vel = X + Y;
        if( vel > 0.0 ) time0 = dist / vel;

        // minus
        dist = L - dist;
        vel = Y - X;
        if( vel > 0.0 ) time1 = dist / vel;
    }
    else
    {
        // plus
        double dist = S - D;
        double vel = Y - X;
        if( vel > 0.0 ) time2 = dist / vel;

        // minus
        dist = L - dist;
        vel = Y + X;
        if( vel > 0.0 ) time3 = dist / vel;
    }

    //cout << min( min( min( time0, time1 ), time2 ), time3 ) << endl;
    /* printf( "% ", min( min( min( time0, time1 ), time2 ), time3 ) ); */
    cout << fixed << setprecision(10) << min( min( min( time0, time1 ), time2 ), time3 ) << endl;
}
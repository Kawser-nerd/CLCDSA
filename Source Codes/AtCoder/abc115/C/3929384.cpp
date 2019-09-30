#include <iostream>
#include <stdlib.h>
#include <vector> //vector
#include <algorithm> //sort()
#include <cstdlib>
#include <cmath>

using namespace std;

//long a, b, c, d, i, j, k, n;


int main(){
//////////////////////////////////////////////////////

    int n, k;
    cin >> n >> k;

    //cout << "n:" << n << endl;
    //cout << "k:" << k << endl;
    //cin >> n;
    vector<long> input(n);
    for (int i = 0 ; i < n ; i ++ )
    {
        cin >> input[i];
        //cout << "input[" << i << "]=" << input[i] << endl  ;
    }

    sort(input.begin() , input.end());

    uint64_t min = numeric_limits<uint64_t>::max();

    

    for ( int i = 0 ; i < n - k + 1 ; i ++ )
    {
        //cout << "input[ n + k - 1 ] : " << input[ i + k - 1 ] << endl;
        //cout << "input[ n ] : " << input[ i ] << endl;

        uint64_t delta = abs( input[ i + k - 1 ] - input[ i ] );
        //cout << "delta : " << delta << endl;
        if ( delta < min )
        {
            min = delta;
        }
    }


    // long sum = 0;
    // for ( int i = 0 ; i < n ; i ++ )
    // {
    //     sum += i;
    // }






    cout <<   min   << endl;

//////////////////////////////////////////////////////
// Ctrl + Opt + N to make
    return 0;
}
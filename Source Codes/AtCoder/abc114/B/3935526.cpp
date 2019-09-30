#include <iostream>
#include <stdlib.h>
#include <vector> //vector
#include <algorithm> //sort()

using namespace std;

//long a, b, c, d, i, j, k, n;


int main(){
//////////////////////////////////////////////////////

    string s(20, '\0');
    cin >> s;

    int k;
    unsigned int min = 999;
    for ( int i = 0 ; i < s.size() - 2 ; ++i )
    {
        //cout << s.substr(i , 3) << endl;
        k = stoi ( s.substr(i, 3) );
        //cout << k << endl;
        if ( abs( k - 753 ) < min )
        {
            min = abs(k - 753 );
        }
    }
    // cout << "n:" << n << endl;

    // vector<long> input(n);
    // for (int i = 0 ; i < n ; i ++ )
    // {
    //     cin >> input[i];
        // cout << "input[" << i << "]=" << input[i] << endl;
    // }

    // sort(input.begin() , input.end());

    // uint64_t max = numeric_limits<uint64_t>::max();




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
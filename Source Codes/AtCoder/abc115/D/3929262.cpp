#include <iostream>
#include <stdlib.h>
#include <vector> //vector
#include <algorithm> //sort()

using namespace std;

//uint64_t a, b, c, d, i, j, k, n;

uint64_t patty ( int n , uint64_t x);

uint64_t a[201];
uint64_t p[201];

int main(){
//////////////////////////////////////////////////////

    int n;
    uint64_t x;
    cin >> n >> x;

    p[0] = 1;
    a[0] = 1;

    for ( int i = 1 ; i <= n ; i ++)
    {
        p[i] = p[i-1]*2+1;
        a[i] = a[i-1]*2+3;
        //cout << i << " p:" << p[i] << " a:" << a[i] <<endl;
    }
    
    cout << patty( n , x) << endl;


    // cin >> n;
    // vector<uint64_t> input[n];
    // for (int i = 0 ; i < n ; i ++ )
    // {
    //     cin >> input[i];
    // }




    // uint64_t sum = 0;
    // for ( int i = 0 ; i < n ; i ++ )
    // {
    //     sum += i;
    // }






    // cout <<      << endl;

//////////////////////////////////////////////////////
// Ctrl + Opt + N to make
    return 0;
}

//n : ??????x : ????????
uint64_t patty ( int n , uint64_t x)
{
    //cout << "patty : n:" << n << " x:" << x << endl;
    if ( n == 0)
    {
        if ( x == 1)
        {
            //cout << "n:" << n << " x:" << x << " patty1 =" <<1 << endl;
            return 1;
        }
        else if(x == 0)
        {
            //cout << "n:" << n << " x:" << x << " patty1 =" <<0 << endl;
           return 0;
        }
        else
        {
            //cout << "error1" << endl;
            return 0;
        }
    }
    if ( x <= 1 )
    {
        //cout << "n:" << n << " x:" << x << " patty1 =" <<0 << endl;
        return 0;
    }

    if ( x <= a[n - 1] + 1)
    {
        uint64_t pt = patty ( n - 1 , x - 1 );
        //cout << "n:" << n << " x:" << x << " patty2 =" << pt << endl;
        return pt;
    }

    if ( x <= a[n - 1] + 2)
    {
        uint64_t pt = patty ( n - 1 , x - 2 ) + 1;
        //cout << "n:" << n << " x:" << x << " patty3 =" << pt << endl;
        return pt;
    }

    if ( x <= a [n - 1] * 2 + 2)
    {
        uint64_t pt = p[n - 1] + 1 + patty( n - 1 , x - a[n - 1] - 2);
        //cout << "n:" << n << " x:" << x << " patty4 =" << pt << endl;
        return pt; 
    }

    if ( x <= a [n - 1] * 2 + 3)
    {
        uint64_t pt = p[n];
        //cout << "n:" << n << " x:" << x << " patty5 =" << pt << endl;
        return p[n];
    }

    //cout << "error2" << endl;
    return p[n];
}
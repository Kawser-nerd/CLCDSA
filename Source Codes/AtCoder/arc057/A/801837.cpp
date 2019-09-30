#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<math.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> TP;


int main()
{
    // get a integer
    ll A, K;
    cin >> A >> K;

    ll T = 2000000000000;

    if( K == 0 )
    {
        cout << T - A << endl;
        return 0;
    }

    ll sum = A;
    ll day = 0;
    while( sum < T )
    {
        sum = sum + 1 + K * sum;
        day++;
    }

    /* if( A != 0 ) */
    /* { */
    /*     T /= A; */
    /* } */

    /* if( T <= 1 ) */
    /* { */
    /*     cout << 0 << endl; */
    /*     return 0; */
    /* } */


    /* /1* K = 1; *1/ */
    /* /1* T = 1; *1/ */

    /* ll day = ceil( log( T ) / log( 1 + K ) ); */
    cout << day << endl;
}
#include <iostream>


using namespace std;


unsigned long long lcm( unsigned long long, unsigned long long );
unsigned long long gcd( unsigned long long, unsigned long long );


// ?????
unsigned long long lcm( unsigned long long x, unsigned long long y ) {
    return x / ( x > y ? gcd( x, y ) : gcd( y, x ) ) * y;
}


// ?????
// ????: x >= y
unsigned long long gcd( unsigned long long x, unsigned long long y ) {
    return y ? gcd( y, x % y ) : x;
}


int main() {
    int N;
    cin >> N;

    unsigned long long T[ N ];
    unsigned long long res = 1;
    for ( int i = 0; i < N; i++ ) {
        cin >> T[ i ];
        res = lcm( res, T[ i ] );
    }

    cout << res << endl;

    return 0;
}
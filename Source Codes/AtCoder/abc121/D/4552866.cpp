#include <iostream>
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

long long f(long long a) {
    long long t, s;

    if (((a+1)/2)%2 == 0) t = 0;
    else t = 1;
   
    if ((a+1)%2 == 0) s = 0;
    else s = a;

    return t ^ s;
}


int main() {
    long long a, b; cin >> a >> b;
    cout << (f(a-1) ^ f(b)) << endl;
    return 0;
}
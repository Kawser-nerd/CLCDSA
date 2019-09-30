#include<iostream>
using namespace std;

int main () {
    int64_t x;
    cin >> x;
    int64_t a = (x / 11LL) * 2LL;
    int64_t b = x % 11LL;
    if (b == 0) ;
    else if (b <= 6) a++;
    else a+=2LL;
    cout << a << endl;
}
#include <iostream>
#include <algorithm>

using namespace std;

double myAbs (double);

int main()
{
    int n, m;
    cin >> n >> m;
    n %= 12;

    double lng = 6.0 * m;
    double shrt = 30.0 * n + 0.5 * m;

    double candi1 = myAbs(lng - shrt);
    double candi2 = 360 - candi1;

    // cout << candi1 << ", " << candi2 << endl;
    cout << ((candi1 < candi2)? candi1 : candi2) << endl;

    return 0;
}

double myAbs (double n)
{
    if (n < 0) return -n;
    else return n;
}
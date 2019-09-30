#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    double A, B, C, D;
    cin >> A >> B >> C >> D;

    double t = B / A;
    double a = D / C;
    string ans;
    if(t > a)
        ans = "TAKAHASHI";
    else if(a > t)
        ans = "AOKI";
    else
        ans = "DRAW";

    cout << ans << endl;
    return 0;
}
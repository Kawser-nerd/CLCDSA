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
    int n;
    cin >> n;

    string ans;
    if(n <= 59)
        ans = "Bad";
    else if(60 <= n && n <= 89)
        ans = "Good";
    else if(90 <= n && n <= 99)
        ans = "Great";
    else
        ans = "Perfect";

    cout << ans << endl;
    return 0;
}
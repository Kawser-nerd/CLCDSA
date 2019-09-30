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
    int A, B, C;
    cin >> A >> B >> C;

    bool apb = false;
    bool amb = false;
    if(C == A + B) apb = true;
    if(C == A - B) amb = true;

    char ans = '!';
    if(apb && amb)
        ans = '?';
    else if(apb)
        ans = '+';
    else if(amb)
        ans = '-';
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    long long x, y, ans;
    ans = 0;
    cin >> x >> y;
    if(x <= y && x >= 0 && y >= 0){
        ans = y - x;
    }
    else if(x > y && x >= 0 && y >= 0){
        ans = ((y == 0) ? 1 : 2) + x - y;
    }
    else if(x >= 0 && y < 0){
        ans = 1 + abs(abs(y) - abs(x));
    }
    else if(abs(x) > abs(y) && x < 0 && y >= 0){
        ans = abs(abs(x) - abs(y)) + ((y == 0) ? 0 : 1);
    }
    else if(abs(x) <= abs(y) && x < 0 && y >= 0){
        ans = 1 + abs(abs(x) - abs(y));
    }
    else if(abs(x) >= abs(y) && x < 0 && y < 0){
        ans = abs(abs(y) - abs(x));
    }
    else if(abs(x) < abs(y) && x < 0 && y < 0){
        ans = 2 + abs(abs(y) - abs(x));
    }
    else {
        cout << "Not match" << endl;
    }
    cout << ans << endl;
}
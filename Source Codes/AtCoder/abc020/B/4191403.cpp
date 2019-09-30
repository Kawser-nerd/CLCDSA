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
    string A, B;
    cin >> A >> B;

    int ans = 0;
    for(auto& e : A)
        ans = ans * 10 + (e - '0');
    for(auto& e : B)
        ans = ans * 10 + (e - '0');

    cout << ans * 2 << endl;
    return 0;
}
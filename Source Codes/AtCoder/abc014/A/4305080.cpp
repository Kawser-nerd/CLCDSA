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
    int a, b;
    cin >> a >> b;

    if(a % b)
        cout << b - a % b << endl;
    else
        cout << 0 << endl;
    return 0;
}
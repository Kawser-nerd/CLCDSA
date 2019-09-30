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
    int M, D;
    cin >> M >> D;
    cout << (M % D ? "NO" : "YES") << endl;
    return 0;
}
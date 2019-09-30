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
    int A, D;
    cin >> A >> D;
    cout << max((A + 1) * D, A * (D + 1)) << endl;
    return 0;
}
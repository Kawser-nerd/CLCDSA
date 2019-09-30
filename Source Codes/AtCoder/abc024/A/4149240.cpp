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
    int A, B, C, K, S, T;
    cin >> A >> B >> C >> K >> S >> T;

    int disc = (S + T >= K ? C : 0);
    cout << S * (A - disc) + T * (B - disc) << endl;
    return 0;
}
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
    cout << (A.size() > B.size() ? A : B) << endl;
    return 0;
}
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
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;

    if(l1 == l2)
        cout << l3 << endl;
    else if(l1 == l3)
        cout << l2 << endl;
    else
        cout << l1 << endl;

    return 0;
}
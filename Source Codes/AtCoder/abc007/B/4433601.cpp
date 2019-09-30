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
    string A;
    cin >> A;

    if(A.size() > 1)
        cout << A[0] << endl;
    else
    {
        if(A[0] == 'a')
            cout << -1 << endl;
        else
            cout << char(A[0] - 1) << endl;
    }
    
    return 0;
}
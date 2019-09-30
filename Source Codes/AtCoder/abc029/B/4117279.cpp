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
    int ans = 0;
    for(int i = 0; i < 12; ++i)
    {
        string si;
        cin >> si;
        if(string::npos != si.find("r"))
            ans++;
    }
    cout << ans << endl;
    return 0;
}
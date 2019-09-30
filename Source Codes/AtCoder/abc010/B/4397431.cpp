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
    int n;
    cin >> n;
    
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        while(ai)
        {
            if((ai % 2) && (2 != ai % 3))
            {
                break;
            }
            ans++;
            ai--;
        }
    }
    cout << ans << endl;
    return 0;
}
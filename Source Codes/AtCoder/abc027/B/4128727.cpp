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
    int N;
    cin >> N;
    vector<int> v(N);
    int sum = 0;
    for(auto& e : v)
    {
        cin >> e;
        sum += e;
    }

    int ans = 0;
    if(sum % N)
    {
        ans = -1;
    }
    else
    {
        const int pn = sum / N;
        int lt = 0;
        for(int i = 0; i < N; ++i)
        {
            lt += v[i];
            if(lt != (pn * (i + 1)))
                ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}
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

    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        int mi;
        cin >> mi;
        if(mi < 80)
            ans += 80 - mi;
    }

    cout << ans << endl;
    return 0;
}
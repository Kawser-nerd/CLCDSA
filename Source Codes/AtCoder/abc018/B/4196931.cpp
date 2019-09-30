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
    string S;
    int N;
    cin >> S >> N;

    string ans = "";
    for(int i = 0; i < N; ++i)
    {
        int li, ri;
        cin >> li >> ri;
        int ai = li - 1;
        ans = S;
        for(ri -= 1, li -= 1; li <= ri; ri--)
            ans[ai++] = S[ri];
        S = ans;
    }

    cout << ans << endl;
    return 0;
}
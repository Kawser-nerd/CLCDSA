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
    cin >> S;

    string ans = S;
    transform(S.begin(), S.end(), ans.begin(), ::tolower);
    ans[0] = ans[0] - 'a' + 'A';
    cout << ans << endl;
    return 0;
}
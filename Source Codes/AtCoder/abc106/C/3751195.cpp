#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    long long k;
    string s, ans;
    cin >> s >> k;
    ans = "1";
    for (long long i = 0; i < k; ++i){
        if (s[i] != '1') {
            ans = s[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
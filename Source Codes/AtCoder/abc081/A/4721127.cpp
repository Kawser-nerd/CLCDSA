#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int result = 0;
    for(auto itr = s.begin(); itr != s.end(); ++itr) {
        if (*itr == '1') {
            ++result;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());

    int N = s.length();
    int M = t.length();
    int m = min(N, M);
    for(int i = 0; i < m; ++i)
    {
        if(s[i] < t[i])
        {
            cout << "Yes" << endl;
            return 0;
        }
        else if(s[i] > t[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    if(N < M) cout << "Yes" << endl;
    else  cout << "No" << endl;

    return 0;
}
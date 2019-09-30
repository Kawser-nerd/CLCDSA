#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    string s;

    cin >> N;
    cin >> s;

    int sum = 0;
    int minv = 0;

    for (int i = 0; i < N;i++)
    {
        sum += s[i] == '(' ? 1 : -1;
        if(minv > sum)
        {
            minv = sum;
        }
    }
    //cout << "minv = " << minv << " sum = " << sum << endl;
    int last = sum;

    string s1(max(-minv, 0), '(');
    string s2(max(last - minv, 0), ')');
    string ans = s1 + s + s2;

    cout << ans << endl;

    return 0;
}
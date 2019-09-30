#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void)
{
    int N;
    string S;
    cin >> N >> S;

    set<char> x;

    int ans = 0;;
    for(int i = 0; i < N - 1; ++i)
    {
        x.insert(S[i]);
        int count = 0;
        for(const auto& e : x)
        {
            if(string::npos != S.find(e, i + 1)) count++;
        }
        if(ans < count) ans = count;
    }

    cout << ans << endl;

    return 0;
}
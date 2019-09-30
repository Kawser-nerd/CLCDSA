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

    vector<string> v(25, "");
    for(int i = 0; i < S.size(); ++i)
    {
        for(int j = 0; j < S.size(); ++j)
        {
            v[5 * i + j] += S[i];
            v[5 * i + j] += S[j];
        }
    }
    sort(v.begin(), v.end());
    cout << v[N - 1] << endl;
    return 0;
}
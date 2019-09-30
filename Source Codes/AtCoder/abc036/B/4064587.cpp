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

    vector<string> v(N);
    for(auto& e : v)
        cin >> e;
    
    for(int j = 0; j < N; ++j)
    {
        for(int i = N - 1; i >= 0; --i)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}
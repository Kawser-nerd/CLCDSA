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
    set<int> s;
    for(int i = 0; i < N; ++i)
    {
        int ai;
        cin >> ai;
        s.insert(ai);
    }

    auto ans = s.rbegin();
    ans++;
    cout << *ans << endl;
    return 0;
}
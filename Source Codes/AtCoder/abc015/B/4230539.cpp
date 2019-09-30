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

    int sum = 0;
    int n = N;
    for(int i = 0; i < N; ++i)
    {
        int ai;
        cin >> ai;
        if(0 == ai)
            n--;
        else
            sum += ai;
    }

    cout << ceil((double)sum / n) << endl;
    return 0;
}
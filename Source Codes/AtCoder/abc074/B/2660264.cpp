#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N, K;

    cin >> N >> K;

    int sum = 0;

    for(int i = 0;i < N;i++)
    {
        int x;
        cin >> x;
        sum += min(x, abs(K - x)) * 2;
    }

    cout << sum << endl;

    return 0;
}
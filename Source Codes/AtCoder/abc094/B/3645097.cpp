#include <iostream>

using namespace std;

int main(void)
{
    int N, M, X;
    cin >> N >> M >> X;

    int cost_l = 0;
    int cost_r = 0;
    for(int i = 0; i < M; ++i)
    {
        int Ai;
        cin >> Ai;
        if(Ai < X) cost_l++;
        if(Ai > X) cost_r++;
    }
    cout << min(cost_l, cost_r) << endl;
    return 0;
}
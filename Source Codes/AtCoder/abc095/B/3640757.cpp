#include <iostream>

using namespace std;

int main(void)
{
    int N, X;
    cin >> N >> X;

    int donuts = 0;
    int mi_min = 1000;
    for(int i = 0; i < N; ++i)
    {
        int mi;
        cin >> mi;
        X -= mi;
        donuts++;
        if(mi < mi_min)
            mi_min = mi;
    }

    cout << (donuts + X / mi_min) << endl;

    return 0;
}
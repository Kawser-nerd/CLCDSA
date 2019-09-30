#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, M, X, Y;

    cin >> N >> M >> X >> Y;

    vector<int> vx(N + 1), vy(M + 1);

    vx[0] = X;
    for(int i = 0; i < N; ++i)
    {
        cin >> vx[i + 1];
    }
    vy[0] = Y;
    for(int i = 0; i < M; ++i)
    {
        cin >> vy[i + 1];
    }

    for(int Z = -100; Z <= 100; ++Z)
    {
        bool pass = true;
        for(int i = 0; i < vx.size(); ++i)
        {
            if(vx[i] >= Z)
            {
                pass = false;
            }
        }
        for(int i = 0; i < vy.size(); ++i)
        {
            if(vy[i] < Z)
            {
                pass = false;
            }
        }
        if(pass)
        {
            cout << "No War" << endl;
            return 0;
        }
    }

    cout << "War" << endl;

    return 0;
}
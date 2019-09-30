#include <iostream>

using namespace std;

int main(void)
{
    int N, D, X;
    cin >> N >> D >> X;

    int choco = 0;
    for(int i = 0; i < N; ++i)
    {
        int Ai;
        cin >> Ai;
        choco += D / Ai;
        if(D % Ai)
            choco++;
    }

    cout << X + choco << endl;

    return 0;
}
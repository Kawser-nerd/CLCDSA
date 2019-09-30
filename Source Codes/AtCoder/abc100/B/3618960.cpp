#include <iostream>

using namespace std;

int main(void)
{
    int div[] = {1, 100, 10000,};

    int D, N; cin >> D >> N;
    if(N == 100) N++;

    cout << div[D] * N << endl;

    return 0;
}
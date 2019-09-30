#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    long long Q, H, S, D, N;
    long long price = 0;
    cin >> Q >> H >> S >> D >> N;
    // replace H and S
    H = min(2 * Q, H);
    S = min(2 * H, S);
    if(N % 2 == 1){
        price = (D <= 2 * S) ? ((N / 2) * D + S) : (N * S);  
    }
    else {
        price = (D <= 2 * S) ? ((N / 2) * D) : (N * S);
    }
    cout << price << endl;
}
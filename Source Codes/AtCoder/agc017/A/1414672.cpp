#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const* argv[])
{
    long N, P;
    cin >> N >> P;
    vector<long> v(N);
    for(int i=0; i<N; i++) cin >> v[i];

    int even = 0, odd = 0, sum;
    for(int i=0; i<N; i++){
        sum += v[i];
        if(v[i]%2 == 0) even++;
        else odd++;
    }


    if(even == N) {
        if(P == 0) {
            cout << (long)pow(2,N);
        }else {
            cout << 0 << endl;
        }
        return 0;
    }

    cout << (long)pow(2,N-1) << endl;
}
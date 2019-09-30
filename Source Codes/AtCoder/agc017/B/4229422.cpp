#include <iostream>

using namespace std;

int main(){
    long N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    for(long n = 0; n < N; n++){
        long m = N-n-1;
        if(A+C*n-D*m <= B && A+D*n-C*m >= B){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
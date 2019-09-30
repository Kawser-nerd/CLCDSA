#include <iostream>
#include <string>

using namespace std;

int main(){
    string S;
    cin >> S;
    long N = S.size();
    long ans = 2*N-2;
    for(long i = 1; i < N-1; i++){
        if(S[i] == 'U') ans += (N-1+i);
        else ans += (N-1+N-1-i);
    }
    cout << ans << endl;
}
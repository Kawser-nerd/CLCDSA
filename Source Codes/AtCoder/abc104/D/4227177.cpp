#include <iostream>
#include <string>

#define P 1000000007

using namespace std;

long a[2][100000];
long ab[3][100000];
long abc[4][100000];

long pow(long n, long m){
    int ans = 1;
    for(int i = 0; i < m; i++){
        ans = (ans*n)%P;
    }
    return ans;
}

int main(){
    string S;
    cin >> S;
    int Q = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '?') Q++;
    }
    if(S[0] == 'A') a[0][0] = 1;
    if(S[0] == '?') a[1][0] = 1;
    for(int i = 1; i < S.size(); i++){
        for(int j = 0; j < 2; j++) a[j][i] = a[j][i-1];
        for(int j = 0; j < 3; j++) ab[j][i] = ab[j][i-1];
        for(int j = 0; j < 4; j++) abc[j][i] = abc[j][i-1];
        if(S[i] == 'A'){
            a[0][i] = (a[0][i-1]+1)%P;
        }
        if(S[i] == 'B'){
            ab[0][i] = (a[0][i-1] + ab[0][i-1])%P;
            ab[1][i] = (a[1][i-1] + ab[1][i-1])%P;
        }
        if(S[i] == 'C'){
            abc[0][i] = (ab[0][i-1] + abc[0][i-1])%P;
            abc[1][i] = (ab[1][i-1] + abc[1][i-1])%P;
            abc[2][i] = (ab[2][i-1] + abc[2][i-1])%P;
        }
        if(S[i] == '?'){
            for(int j = 1; j < 2; j++) a[j][i] = (a[j][i-1] + 1)%P;
            for(int j = 1; j < 3; j++) ab[j][i] = (ab[j][i-1] + a[j-1][i-1])%P;
            for(int j = 1; j < 4; j++) abc[j][i] = (abc[j][i-1] + ab[j-1][i-1])%P;
        }
    }
    long ans = 0;
    ans = (abc[0][S.size()-1]*pow(3, Q))%P + (abc[1][S.size()-1]*pow(3, Q-1))%P + (abc[2][S.size()-1]*pow(3, Q-2))%P + (abc[3][S.size()-1]*pow(3, Q-3))%P;
    ans = ans%P;
    
    cout << ans << endl;
}
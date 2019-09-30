#include <iostream>

using namespace std;

int main(){
    int N;
    long K;
    long A[100000];
    long X = 0;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i <= 40; i++){
        long n = (long)1 << i;
        if(n > K) break;
        int cnt1 = 0;
        int cnt0 = 0;
        for(int j = 0; j < N; j++){
            if(n&A[j]) cnt1++;
            else cnt0++;
            //cout << n << ' ' << A[i] << endl;
        }
        if(cnt0 > cnt1){
            X = X | n;
        }
    }
    
    //cout << X << endl;
    long long ans = 0;
    long long tmp = 0;
    for(int i = 0; i < N; i++){
        ans += K^A[i];
    }
    if(X <= K){
        for(int i = 0; i < N; i++){
            tmp += (X^A[i]);
        }
    }
    ans = max(tmp, ans);
    for(int j = 0; j <= 40; j++){
        tmp = 0;
        long n = (long)1 << j;
        if(K & n){
            //cout << "j " << j << endl;
            long long X1 = 0;
            for(int k = 0; k < j; k++){
                X1 += X&((long)1 << k);
                //cout << X1 << endl;
            }
            for(int k = j+1; k <= 40; k++){
                //if((1<< k) > K) break;
                //cout << k << endl;
                X1 += K&((long)1 << k);
            }
            for(int i = 0; i < N; i++){
                tmp += (X1^A[i]);
            }
            //cout << X1 << endl;
            ans = max(tmp, ans);
        }
    }
    cout << ans << endl;
}
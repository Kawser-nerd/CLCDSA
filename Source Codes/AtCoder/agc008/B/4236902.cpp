#include <iostream>

using namespace std;

int main(){
    int N, K;
    long ans = 0;
    long a[100000];
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    long cumsum[100001];
    long possum[100001];
    cumsum[0] = 0;
    possum[0] = 0;
    for(int i = 1; i <= N;i++){
        cumsum[i] = cumsum[i-1]+a[i-1];
        possum[i] = possum[i-1];
        if(a[i-1] > 0) possum[i] += a[i-1]; 
        //cout << cumsum[i] << ' ' << possum[i] << endl;
    }
    for(int i = 0; i+K-1 < N; i++){
        long tmp;
        tmp = possum[i] + possum[N] - possum[i+K];
        //cout << tmp << endl;
        ans = max(ans, tmp);
        ans = max(ans, tmp+cumsum[i+K]-cumsum[i]);
    }
    cout << ans << endl;
}
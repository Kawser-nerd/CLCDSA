#include <iostream>
#include <algorithm>

using namespace std;

int bit[200001];
int N, K;

int sum(int i){
    int s = 0;
    while(i > 0){
        s += bit[i];
        i-= i&-i;
    }
    return s;
}

void add(int i, int x){
    while(i <= N){
        bit[i] += x;
        i += i & -i;
    }
}

typedef pair<long, int> P;
int main(){
    cin >> N >> K;
    long b[200000];
    P S[200000];
    int idx[200000];
    long ans = 0;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        b[i] = a - K;
        if(i == 0) {
            S[0].first = b[0];
            S[0].second = 0;
        }else{
            S[i].first = S[i-1].first+b[i];
            S[i].second = i;
        }
        if(S[i].first >= 0) ans += 1;
    }
    sort(S, S+N);
    for(int i = 0; i < N; i++){
        idx[S[i].second] = i;
    }
    //cout << ans << endl;
    for(int i = 0; i < N; i++){
        ans += sum(S[i].second+1);
        add(S[i].second+1, 1);
    }
    cout << ans << endl;
}
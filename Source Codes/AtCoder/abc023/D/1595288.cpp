#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> H, S;

bool judge(long long P){
    vector<long long> a(N);
    for(int i=0; i<N; i++){
        if(P < H[i]) return false;
        long long T = (P-H[i])/S[i];
        a[i] = T;
    }
    sort(a.begin(), a.end());
    for(int i=0; i<N; i++)
        if(a[i] < i)
            return false;
    return true;
}

int main(){
    cin >> N;
    H.resize(N);
    S.resize(N);
    for(int i=0; i<N; i++) cin >> H[i] >> S[i];
    long long ub = 1LL << 60;
    long long lb = 0;
    while(ub - lb > 1){
        long long mid = (ub-lb)/2+lb;
        if(judge(mid)) ub = mid;
        else lb = mid;
    }
    cout << ub << endl;
    return 0;
}
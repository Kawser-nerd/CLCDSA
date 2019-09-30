#include <iostream>
#include <vector>

using namespace std;

typedef pair<long, long> P;

long sum(long n){
    long tmp = 1;
    long ans = 0;
    while(tmp <= n){
        ans += (n%(tmp*10)-ans)/tmp;
        tmp *= 10;
    }
    return ans;
}

int main(){
    int K;
    
    vector<P> v;
    cin >> K;
    long pow[16];
    pow[0] = 1;
    for(int i = 1; i <= 15; i++) pow[i] = pow[i-1]*10;

    for(int i = 1; i <= 15; i++){
        if(i == 1){
            for(int j = 1; j <= 9; j++){
                v.push_back(P(j, sum(j)));
            }
        }
        if(i == 2){
            for(int j = 10; j <= 99; j++){
                v.push_back(P(j, sum(j)));
            }
        }
        if(i == 3){
            for(int j = 100; j <= 999; j++){
                v.push_back(P(j, sum(j)));
            }
        }
        if(i >= 4){
            for(int j = 1000; j <= 9999; j++){
                v.push_back(P(j*pow[i-4]+pow[i-4]-1, sum(j*pow[i-4]+pow[i-4]-1)));
            }
        }
    }
    double tmp_min = 10e+16;
    vector<long> ans;
    for(int i = v.size()-1; i >= 0; i--){
        if(tmp_min >= (double)v[i].first/(double)v[i].second) {
            ans.push_back(v[i].first);
            tmp_min = (double)v[i].first/(double)v[i].second;
        }
    }
    
    for(int i = 1; i <= K; i++){
        cout << ans[ans.size()-i];
        if(i != K) cout << ' ';
        else cout << endl;
    }
}
#include <stdio.h>
#include <vector>
using namespace std;

#define ll long long
#define MAX_N 100000

ll max_(ll a, ll b){
    if(a < b){
        return b;
    }
    return a;
}

int main(void){
    ll N, C;
    scanf("%lld", &N);
    scanf("%lld", &C);

    vector<pair<ll, ll>> vec;
    ll x_, v_;
    for(int i = 0; i < N; i++){
        scanf("%lld", &x_);
        scanf("%lld", &v_);
        vec.push_back(make_pair(x_, v_));
    }

    ll Cr1[MAX_N + 1];
    ll Cr2[MAX_N + 1];
    Cr1[0] = 0;
    Cr2[0] = 0;
    ll sum_v = 0;
    for(int i = 1; i <= N; i++){
        sum_v += vec[i - 1].second;
        Cr1[i] = max(sum_v - vec[i - 1].first, Cr1[i - 1]);
        Cr2[i] = max(sum_v - vec[i - 1].first * 2, Cr2[i - 1]);
    }
    
    ll Cl1[MAX_N + 1];
    ll Cl2[MAX_N + 1];
    Cl1[0] = 0;
    Cl2[0] = 0;
    sum_v = 0;
    for(int i = 1; i <= N; i++){
        sum_v += vec[N - i].second;
        Cl1[i] = max(sum_v - (C - vec[N - i].first), Cl1[i - 1]);
        Cl2[i] = max(sum_v - (C - vec[N - i].first) * 2, Cl2[i - 1]);
    }

    ll max_right_c = 0;
    for (int i = 0; i <= N; i++){
        max_right_c = max_(max_(Cr1[i] + Cl2[N - i], Cr2[i] + Cl1[N - i]), max_right_c);
        //printf("%lld\n", max_right_c);
    }

    /*
    for(int i = 0; i <= N; i++){
        printf("Cr1[%d] %lld\n", i, Cr1[i]);
    }
    for(int i = 0; i <= N; i++){
        printf("Cr2[%d] %lld\n", i, Cr2[i]);
    }
    for(int i = 0; i <= N; i++){
        printf("Cl1[%d] %lld\n", i, Cl1[i]);
    }
    for(int i = 0; i <= N; i++){
        printf("Cl2[%d] %lld\n", i, Cl2[i]);
    }
    */


    printf("%lld\n", max_right_c);

    return 0;
}